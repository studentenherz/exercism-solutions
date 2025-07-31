#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

fn is_sublist<T: PartialEq>(_first_list: &[T], _second_list: &[T]) -> bool {
    _first_list.is_empty()
        || (_second_list.len() > _first_list.len())
            && _second_list
                .windows(_first_list.len())
                .any(|win| win == _first_list)
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
