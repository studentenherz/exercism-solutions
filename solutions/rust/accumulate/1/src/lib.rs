pub fn map<T, U, F>(input: Vec<T>, mut f: F) -> Vec<U>
where
    F: FnMut(T) -> U,
{
    let mut ans = Vec::<U>::new();
    for x in input {
        ans.push(f(x));
    }
    ans
}
