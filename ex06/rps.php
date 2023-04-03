<?php

$user = readline("Select rock, paper, or scissors: ");

$computer = rand(1, 3);
if ($computer == 1) {
    $computer = "rock";
} elseif ($compute == 2) {
    $computer = "paper";
} else {
    $computer = "scissors";
}

if ($user == $computer_choice) {
    echo "It's a tie!\n";
} elseif (($user == "rock" && $computer == "scissors") || ($user == "paper" && $computer == "rock") || ($user == "scissors" && $computer == "paper")) {
    echo "You win! The computer chose $computer.\n";
} else {
    echo "You lose! The computer chose $computer.\n";
}
