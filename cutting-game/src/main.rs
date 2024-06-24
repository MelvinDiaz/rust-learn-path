use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    let mut t: u32 = input.trim().parse().expect("Not an integer!");
    while t > 0 {
        let mut input = String::new();

        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");

        let inputs: Vec<u32> = input
            .trim_end()
            .split(" ")
            .map(|x| x.parse().expect("Not an integer!"))
            .collect();

        let x = inputs[0] as usize;
        let y = inputs[1] as usize;
        let n_chips = inputs[2];
        let moves = inputs[3];

        let mut board_game: Vec<Vec<u32>> = vec![vec![0; x + 1]; y + 1];

        for _ in 0..n_chips {
            let mut input = String::new();
            io::stdin()
                .read_line(&mut input)
                .expect("Failed to read line");

            let inputs: Vec<u32> = input
                .trim_end()
                .split(" ")
                .map(|x| x.parse().expect("Not an integer!"))
                .collect();

            let x_i = inputs[0] as usize;
            let y_i = inputs[1] as usize;

            board_game[x_i][y_i] = 1;
        }

        let mut alice_points: u32 = 0;
        let mut bob_points: u32 = 0;

        for turn in 0..moves {
            let mut input = String::new();
            io::stdin()
                .read_line(&mut input)
                .expect("Failed to read line");

            let inputs: Vec<&str> = input.trim_end().split(" ").collect();

            let c = inputs[0].chars().next().expect("Not a char!");
            let k: u32 = inputs[1].parse().expect("Not an integer!");

            match c {
                'U' => {
                    for _ in 0..k {
                        if let Some(row) = board_game.get(0) {
                            if row.iter().any(|&x| x == 1) {
                                if turn % 2 == 0 {
                                    alice_points += row.iter().sum::<u32>();
                                } else {
                                    bob_points += row.iter().sum::<u32>();
                                }
                            }
                        }
                        board_game.remove(0);
                    }
                }
                'D' => {
                    for _ in 0..k {
                        if let Some(row) = board_game.get(board_game.len() - 1) {
                            if row.iter().any(|&x| x == 1) {
                                if turn % 2 == 0 {
                                    alice_points += row.iter().sum::<u32>();
                                } else {
                                    bob_points += row.iter().sum::<u32>();
                                }
                            }
                        }

                        board_game.remove(board_game.len() - 1);
                    }
                }
                'R' => {
                    let len = board_game[0].len() - 1;
                    for _ in 0..k {
                        for row in &board_game {
                            if let Some(&value) = row.get(len) {
                                if turn % 2 == 0 {
                                    alice_points += value;
                                } else {
                                    bob_points += value;
                                }
                            }
                        }
                        remove_column(&mut board_game, len);
                    }
                }
                'L' => {
                    for _ in 0..k {
                        for row in &board_game {
                            if let Some(&value) = row.get(0) {
                                if turn % 2 == 0 {
                                    alice_points += value;
                                } else {
                                    bob_points += value;
                                }
                            }
                        }
                        remove_column(&mut board_game, 0);
                    }
                }
                _ => {
                    println!("Invalid move!");
                }
            }
        }

        println!("{} {}", alice_points, bob_points);

        t -= 1;
    }
}

fn remove_column(board_game: &mut Vec<Vec<u32>>, y: usize) {
    for row in board_game.iter_mut() {
        if y < row.len() {
            row.remove(y);
        }
    }
}
