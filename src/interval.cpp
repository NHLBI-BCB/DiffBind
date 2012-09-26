#include <string>
#include <sstream>
#include "interval.h"

bode::Interval::Interval(std::string const &chr,int l,int r) {
  _chrom = chr;
  _left = l;
  _right = r;
  _mapped = true;
  _strand = 1;
}

bode::Interval::Interval(std::string const &chr,int l,int r,int s) {
  _chrom = chr;
  _left = l;
  _right = r;
  _mapped = true;
  _strand = s;
}

bode::Interval::Interval(Interval const &i) {
  _chrom = i._chrom;
  _left = i._left;
  _right = i._right;
  _mapped = i._mapped;
  _strand = i._strand;
}

bode::Interval &bode::Interval::operator=(Interval const &i) {
  if (this != &i) {
    _chrom = i._chrom;
    _left = i._left;
    _right = i._right;
    _mapped = i._mapped;
    _strand = i._strand;
  }
  return *this;
}

bool bode::operator==(bode::Interval const &l,bode::Interval const &r) {
  return (l._chrom == r._chrom &&
          l._left == r._left &&
          l._right == r._right &&
          l._strand == r._strand);
}

bool bode::operator<(Interval const &l,Interval const &r) {
  return (l._chrom < r._chrom ||
          (l._chrom == r._chrom && l._left < r._left) ||
          (l._chrom == r._chrom && l._left == r._left && l._right < r._right) ||
          (l._chrom == r._chrom && l._left == r._left && l._right == r._right && l._strand > r._strand));
}

void bode::Interval::update(std::string const &chr,int l,int r) {
  _chrom = chr;
  _left = l;
  _right = r;
  _mapped = true;
}

void bode::Interval::update(std::string const &chr,int l,int r,int s) {
  _chrom = chr;
  _left = l;
  _right = r;
  _mapped = true;
  _strand = s;
}

std::string bode::Interval::format(void) const {
  std::ostringstream out;
  out << _chrom << ":" << _left << "-" << _right;
  return out.str();
}

void bode::Interval::extend(int insertLen) {
  if (_strand > 0) {
    _right = _left + insertLen;
  } else {
    _left = _right - insertLen;
  }
}
