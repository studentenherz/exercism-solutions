// This stub file contains items that aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

pub fn divmod(dividend: i16, divisor: i16) -> (i16, i16) {
    (dividend / divisor, dividend % divisor)
}

pub fn evens<T>(iter: impl Iterator<Item = T>) -> impl Iterator<Item = T> {
    iter.enumerate()
        .filter(|(i, value)| i % 2 == 0)
        .map(|(i, val)| val)
}

pub struct Position(pub i16, pub i16);
impl Position {
    pub fn manhattan(&self) -> i16 {
        let Position(x, y) = self;
        x.abs() + y.abs()
    }
}
