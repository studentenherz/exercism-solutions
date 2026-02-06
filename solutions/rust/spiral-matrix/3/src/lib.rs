enum Dir {
    Up,
    Right,
    Down,
    Left,
}

impl Dir {
    pub fn next(&self) -> Self {
        match self {
            Self::Up => Self::Right,
            Self::Right => Self::Down,
            Self::Down => Self::Left,
            Self::Left => Self::Up,
        }
    }
}

struct Cursor {
    index: usize,
    x: usize,
    y: usize,
    dir: Dir,
    y_max: usize,
    x_max: usize,
    y_min: usize,
    x_min: usize,
    n: usize,
}

impl Cursor {
    pub fn new(width: usize, height: usize) -> Self {
        Self {
            index: 0,
            x: 0,
            y: 0,
            dir: Dir::Right,
            y_max: width,
            x_max: height,
            x_min: 0,
            y_min: 0,
            n: width * height,
        }
    }
}

impl Iterator for Cursor {
    type Item = (usize, usize, usize);
    fn next(&mut self) -> Option<Self::Item> {
        if self.index == self.n {
            return None;
        }

        let result = Some((self.index, self.x, self.y));

        // Turn
        match self.dir {
            Dir::Right if self.y + 1 == self.y_max => {
                self.dir = self.dir.next();
                self.x_min += 1;
            }
            Dir::Down if self.x + 1 == self.x_max => {
                self.dir = self.dir.next();
                self.y_max -= 1;
            }
            Dir::Left if self.y == self.y_min => {
                self.dir = self.dir.next();
                self.x_max -= 1;
            }
            Dir::Up if self.x == self.x_min => {
                self.dir = self.dir.next();
                self.y_min += 1;
            }
            _ => {}
        }

        // Advance
        match self.dir {
            Dir::Right => self.y += 1,
            Dir::Down => self.x += 1,
            Dir::Left => self.y -= 1,
            Dir::Up => self.x -= 1,
        }
        self.index += 1;

        result
    }
}

pub fn spiral_matrix(size: u32) -> Vec<Vec<u32>> {
    let size = size as usize;
    let mut mat = vec![vec![0; size]; size];

    let cursor = Cursor::new(size, size);

    for (index, i, j) in cursor {
        mat[i][j] = index as u32 + 1;
    }

    mat
}
