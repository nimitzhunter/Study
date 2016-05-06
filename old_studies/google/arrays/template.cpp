#include <cstring>
#include <string>

template<typename T>
inline T const & max (T const & a, T const &b){
  return a<b ? b:a;
}

template<typename T>
inline T const * const & max (T const * const &a, T const * const & b){
  auto res = std::strcmp(a,b);
  return res<0 ? b:a;
}

template<typename T>
inline T const & max (T const &a, T const& b, T const& c){
  return max(max(a,b),c);
}

int main(){
  char const * s1 = "s1";
  char const * s2 = "s2";
  char const * s3 = "s3";
  ::max(s1, s2, s3);
}
