use std::io::{self, Write};

fn main() {
    print!("Enter anything: ");
    io::stdout().flush().unwrap(); // Flush to ensure prompt shows before input

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");

    let ch = input.chars().next();

    match ch {
        Some(c) if c.is_alphabetic() => {
            println!("It is an alphabet and its ASCII value is {}", c as u8);
        }
        Some(c) if c.is_digit(10) => {
            println!("It is a number and its ASCII value is {}", c as u8);
        }
        Some(_) => {
            println!("Nothing");
        }
        None => {
            println!("No input detected");
        }
    }
}
