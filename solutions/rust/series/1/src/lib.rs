pub fn series(digits: &str, len: usize) -> Vec<String> {
    let mut ans = Vec::<String>::new();

    let mut i = 0;
    while i + len <= digits.len() {
        ans.push(String::from(&digits[i..(i + len)]));
        i += 1;
    }

    ans
}
