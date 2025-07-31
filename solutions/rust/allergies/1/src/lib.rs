use std::fs::copy;

pub struct Allergies {
    score: u32,
}

#[derive(Debug, PartialEq, Eq)]
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
        match self {
            Self::Eggs => 1 << 0 as u32,
            Self::Peanuts => 1 << 1 as u32,
            Self::Shellfish => 1 << 2 as u32,
            Self::Strawberries => 1 << 3 as u32,
            Self::Tomatoes => 1 << 4 as u32,
            Self::Chocolate => 1 << 5 as u32,
            Self::Pollen => 1 << 6 as u32,
            Self::Cats => 1 << 7 as u32,
        }
    }
}

impl Allergies {
    pub fn new(score: u32) -> Self {
        Allergies { score }
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        self.score & allergen.value() == allergen.value()
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        let mut _allergies: Vec<Allergen> = vec![];

        for allergen in [
            Allergen::Eggs,
            Allergen::Peanuts,
            Allergen::Shellfish,
            Allergen::Strawberries,
            Allergen::Tomatoes,
            Allergen::Chocolate,
            Allergen::Pollen,
            Allergen::Cats,
        ] {
            if self.score & allergen.value() == allergen.value() {
                _allergies.push(allergen);
            }
        }

        _allergies
    }
}
