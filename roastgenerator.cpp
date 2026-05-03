// ============================================================
//  🔥 The Ultimate Roast Generator 🔥
//  A beginner-friendly C++ program that roasts you (lovingly)
// ============================================================

#include <iostream>   // For input/output (cin, cout)
#include <string>     // For the string data type
#include <vector>     // For the vector (like a resizable list)
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time() — used to seed the random number

// --- Helper Function ---
// This function finds {name} inside a template string
// and replaces it with the actual name the user typed.
std::string replacePlaceholder(std::string roastTemplate, const std::string& name) {
    // "{name}" is the placeholder we'll search for
    std::string placeholder = "{name}";

    // find() returns the position (index) of "{name}" in the string,
    // or std::string::npos if it's not found
    size_t position = roastTemplate.find(placeholder);

    // If we found the placeholder, replace it with the real name
    if (position != std::string::npos) {
        roastTemplate.replace(position, placeholder.length(), name);
    }

    return roastTemplate; // Return the updated string
}

int main() {

    // -------------------------------------------------------
    // STEP 1: Seed the random number generator
    // -------------------------------------------------------
    // srand() "seeds" the randomizer so we get different results every run.
    // time(0) returns the current time in seconds — always changing!
    srand(static_cast<unsigned int>(time(0)));

    // -------------------------------------------------------
    // STEP 2: Store all roast templates in a vector
    // -------------------------------------------------------
    // A vector is like a list that can hold multiple items.
    // Each string below is one roast template.
    // {name} is a placeholder — we'll swap it for the real name later.
    std::vector<std::string> roasts = {
        "{name}'s code is so bad, even Stack Overflow deleted their account.",
        "{name} uses bubble sort in interviews and calls it 'optimized for readability'.",
        "I've seen better logic in a corrupted BIOS than in {name}'s pull requests.",
        "{name} still thinks HTML is a programming language — and honestly, it shows.",
        "{name}'s Git history is just 500 commits that all say 'fix bug' and 'fix fix bug'.",
        "They told {name} to write clean code. They opened Notepad and stared at a blank file for 3 hours.",
        "{name}'s idea of debugging is adding more print statements until the computer begs for mercy.",
        "The compiler doesn't throw errors for {name} — it throws tantrums.",
        "{name} once tried to center a div and ended up changing careers for a month.",
        "NASA has better code reliability in their 1977 Voyager probe than {name} has in their Hello World.",
        "{name}'s code has more memory leaks than a broken bucket in a swimming pool.",
        "Roses are red, semicolons are blue. {name} forgot one, now nothing will compile.",
        "{name} wrote their first recursive function and called tech support when the stack overflowed.",
        "They asked {name} to make the website faster. {name} used a loading GIF and called it 'perceived performance'.",
        "{name}'s variable names are so bad, even the compiler files an HR complaint.",
    };

    // -------------------------------------------------------
    // STEP 3: Show the welcome banner (only once, before the loop)
    // -------------------------------------------------------
    std::cout << "==========================================" << std::endl;
    std::cout << "   🔥  Welcome to the Roast Generator  🔥" << std::endl;
    std::cout << "==========================================" << std::endl;

    // -------------------------------------------------------
    // STEP 4: Loop — runs at least 2 times guaranteed
    // -------------------------------------------------------
    // We use a do-while loop because it always executes the body
    // FIRST, then checks the condition. This ensures at least 2 runs
    // by tracking how many rounds have happened with a counter.

    int roundNumber = 0;   // Keeps track of which round we're on
    char playAgain = 'y';  // Stores the user's yes/no answer

    do {
        roundNumber++; // Increment round counter each time the loop runs

        std::cout << "\n--- Round " << roundNumber << " ---" << std::endl;

        // -------------------------------------------------------
        // Ask the user for their name
        // -------------------------------------------------------
        std::string userName;
        std::cout << "Enter your name (if you dare): ";
        std::getline(std::cin, userName); // getline reads full name, including spaces

        // Handle empty input
        if (userName.empty()) {
            userName = "Anonymous Developer";
        }

        // -------------------------------------------------------
        // Pick a random roast
        // -------------------------------------------------------
        // rand() gives a big random number.
        // We use % (modulo) with the vector's size to keep the index in range.
        // Example: if rand() = 57 and there are 15 roasts, 57 % 15 = 12 → index 12
        int randomIndex = rand() % roasts.size();

        // Grab the roast template at that random index
        std::string selectedRoast = roasts[randomIndex];

        // -------------------------------------------------------
        // Replace {name} with the user's actual name
        // -------------------------------------------------------
        std::string finalRoast = replacePlaceholder(selectedRoast, userName);

        // -------------------------------------------------------
        // Display the roast!
        // -------------------------------------------------------
        std::cout << "\n------------------------------------------" << std::endl;
        std::cout << "🎤 Today's roast for " << userName << ":" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "\n  \"" << finalRoast << "\"\n" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "😂 All in good fun, " << userName << "! No hard feelings." << std::endl;
        std::cout << "==========================================" << std::endl;

        // -------------------------------------------------------
        // Ask to continue — but only AFTER at least 2 rounds
        // -------------------------------------------------------
        // roundNumber < 2 means we force another round without asking.
        // Once 2 rounds are done, we ask the user if they want more.
        if (roundNumber < 2) {
            std::cout << "\n🔁 Round " << roundNumber << " done! One more coming up...\n" << std::endl;
        } else {
            std::cout << "\nRoast another victim? (y/n): ";
            std::cin >> playAgain;
            std::cin.ignore(); // Clear the leftover newline so getline works next time
        }

    } while (roundNumber < 2 || playAgain == 'y' || playAgain == 'Y');
    // Loop continues if:
    //   - fewer than 2 rounds have run (roundNumber < 2), OR
    //   - the user typed 'y' or 'Y' to keep going

    std::cout << "\nThanks for playing! Your code is still terrible. 👋" << std::endl;

    return 0; // 0 means the program ended successfully
}