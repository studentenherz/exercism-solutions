struct Dir {
    dx: i32,
    dy: i32,
}

const DIRS: [Dir; 4] = [
    Dir { dx: 0, dy: 1 },
    Dir { dx: 1, dy: 0 },
    Dir { dx: 0, dy: -1 },
    Dir { dx: -1, dy: 0 },
];

pub fn spiral_matrix(size: u32) -> Vec<Vec<u32>> {
    let mut mat = vec![vec![0; size as usize]; size as usize];

    let mut x: i32 = 0;
    let mut y: i32 = 0;
    let mut dir = 0;

    for i in 1..=(size * size) {
        mat[x as usize][y as usize] = i;
        let Dir { dx, dy } = DIRS[(dir % 4) as usize];
        let mut new_x = x + dx;
        let mut new_y = y + dy;
        if new_x >= size as i32
            || new_x < 0
            || new_y >= size as i32
            || new_y < 0
            || mat[new_x as usize][new_y as usize] != 0
        {
            dir += 1;
            let Dir { dx, dy } = DIRS[(dir % 4) as usize];
            new_x = x + dx;
            new_y = y + dy;
        }

        x = new_x;
        y = new_y;
    }

    mat
}
