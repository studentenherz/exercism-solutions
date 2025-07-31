#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

fn kmp<T: PartialEq>(needle: &[T], haystack: &[T]) -> bool {
    let mut table = vec![0_i32; needle.len()];
    table[0] = -1;

    let mut i: usize = 1;
    let mut k: i32 = 0;

    while i < needle.len() {
        if needle[i] == needle[k as usize] {
            table[i] = table[k as usize];
        } else {
            table[i] = k;
            while k >= 0 && (needle[i] != needle[k as usize]) {
                k = table[k as usize];
            }
        }
        i += 1;
        k += 1;
    }

    i = 0;
    k = 0;

    while i < haystack.len() {
        if haystack[i] == needle[k as usize] {
            i += 1;
            k += 1;
            if k as usize == needle.len() {
                return true;
            }
        } else {
            k = table[k as usize];
            if k < 0 {
                i += 1;
                k += 1;
            }
        }
    }

    false
}

fn is_sublist<T: PartialEq>(_first_list: &[T], _second_list: &[T]) -> bool {
    _first_list.is_empty()
        || (_second_list.len() > _first_list.len()) && kmp(_first_list, _second_list)
}

pub fn sublist<T: PartialEq>(_first_list: &[T], _second_list: &[T]) -> Comparison {
    if _first_list == _second_list {
        Comparison::Equal
    } else if is_sublist(_first_list, _second_list) {
        Comparison::Sublist
    } else if is_sublist(_second_list, _first_list) {
        Comparison::Superlist
    } else {
        Comparison::Unequal
    }
}
