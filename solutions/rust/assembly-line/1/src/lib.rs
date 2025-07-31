pub fn production_rate_per_hour(speed: u8) -> f64 {
    let produced = (speed as u16 * 221) as f64;
    match speed {
        0..=4 => produced,
        5..=8 => 0.9 * produced,
        _ => 0.77 * produced,
    }
}

pub fn working_items_per_minute(speed: u8) -> u32 {
    (production_rate_per_hour(speed) / 60f64) as u32
}
