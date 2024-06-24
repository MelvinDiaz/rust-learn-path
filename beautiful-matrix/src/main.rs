use std::io;

fn main() {
    let mut matrix = [[0; 5]; 5];
    let mut location: [usize; 2] = [0, 0];

    for i in 0..5 {
        let mut line = String::new();
        io::stdin()
            .read_line(&mut line)
            .expect("Failed to read line");

        let inputs: Vec<u32> = line
            .trim_end()
            .split(" ")
            .map(|x| x.parse().expect("Not an integer!"))
            .collect();

        for j in 0..5 {
            matrix[i][j] = inputs[j];
            if inputs[j] == 1 {
                location = [i, j];
            }
        }
    }

    print!(
        "{}",
        (location[0] as i32 - 2).abs() + (location[1] as i32 - 2).abs()
    );
}
