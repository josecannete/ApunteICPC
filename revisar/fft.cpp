const double PI = 3.141592653589793;
//NO USAR complex<double> JAMAS POR QUE DA TLE
struct cmplx{
  double x,y;
  cmplx(double x = 0.0, double y = 0.0) : x(x), y(y) {}

  double real(){
    return x;
  }

  cmplx operator+(cmplx z){
    return cmplx(x+z.x,y+z.y);
  }

  cmplx operator-(cmplx z){
    return cmplx(x-z.x,y-z.y);
  }

  cmplx operator*(cmplx z){
    return cmplx(x*z.x-y*z.y,x*z.y+y*z.x);
  }
};

cmplx &operator+=(cmplx &z1, cmplx z2){
  return z1 = z1+z2;
}

cmplx &operator*=(cmplx &z1, cmplx z2){
  return z1 = z1*z2;
}

cmplx &operator/=(cmplx &z1, double a){
  return z1 = cmplx(z1.x/a,z1.y/a);
}

void fft (vector<cmplx> & a, bool invert) 
{
  int n = (int) a.size();
 
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1)
      j -= bit;
    j += bit;
    if (i < j)
      swap (a[i], a[j]);
  }
 
  for (int len=2; len<=n; len<<=1) {
    double ang = 2*PI/len * (invert ? -1 : 1);
    cmplx wlen (cos(ang), sin(ang));
    for (int i=0; i<n; i+=len) {
      cmplx w (1);
      for (int j=0; j<len/2; ++j) {
        cmplx u = a[i+j],  v = a[i+j+len/2] * w;
        a[i+j] = u + v;
        a[i+j+len/2] = u - v;
        w *= wlen;
      }
    }
  }
  if (invert)
    for (int i=0; i<n; ++i)
      a[i] /= n;
}

void multiply (vector<int> & a, vector<int> & b, vector<int> & res) 
{
  vector<cmplx> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
  size_t n = 1; int M = max(a.size(),b.size());
  while (n < M)  n <<= 1;
  n <<= 1;
  fa.resize (n),  fb.resize (n);
 
  fft (fa, false),  fft (fb, false);
  for (size_t i=0; i<n; ++i)
    fa[i] *= fb[i];
  fft (fa, true);
 
  res.resize (n);
  for (size_t i=0; i<n; ++i)
    res[i] = (int)round(fa[i].real());
}
