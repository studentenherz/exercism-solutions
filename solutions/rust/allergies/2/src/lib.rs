use strum::IntoEnumIterator;
use strum_macros::EnumIter;

pub struct Allergies {
    score: u32,
}

#[derive(Debug, PartialEq, Eq, EnumIter, Clone, Copy)]
pub enum Allergen {
    Eggs,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats,
}

impl Allergen {
    pub fn value(&self) -> u32 {
        1 << (*self as usize)
    }
}

impl Allergies {
    pub fn new(score: u32) -> Self {
        Allergies { score }
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        self.score & allergen.value() != 0
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        let mut _allergies: Vec<Allergen> = vec![];

        for allergen in Allergen::iter() {
            if self.score & allergen.value() == allergen.value() {
                _allergies.push(allergen);
            }
        }

        _allergies
    }
}
