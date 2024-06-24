fn main() {
    let input = read_string();
    let second_input = read_string();
    if input > second_input {
        print!("1");
    } else if input == second_input {
        print!("0");
    } else {
        print!("-1");
    }
}

fn read_string() -> String {
    let mut input = String::new();
    std::io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    input.to_lowercase() //returns
}
