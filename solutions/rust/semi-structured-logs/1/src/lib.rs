// This stub file contains items that aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

/// various log levels
#[derive(Clone, PartialEq, Eq, Debug)]
pub enum LogLevel {
    Info,
    Warning,
    Error,
		Debug
}
/// primary function for emitting logs
pub fn log(level: LogLevel, message: &str) -> String {
    let level_str = match level {
			LogLevel::Info => "INFO",
			LogLevel::Warning => "WARNING",
			LogLevel::Error => "ERROR",
			LogLevel::Debug => "DEBUG",
			_ => panic!("Unrecognized log level")
		};

		format!("[{}]: {}", level_str, message)
}

pub fn info(message: &str) -> String {
  log(LogLevel::Info, message)
}

pub fn warn(message: &str) -> String {
	log(LogLevel::Warning, message)
}

pub fn error(message: &str) -> String {
	log(LogLevel::Error, message)
}
