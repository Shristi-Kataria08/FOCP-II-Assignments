// ============================================================
//  📚 The Homework Excuse Generator 📚
//  A beginner-friendly C++ program that generates creative
//  excuses for missing homework — all in good fun!
// ============================================================

#include <iostream>   // For input/output (cin, cout)
#include <string>     // For the string data type
#include <vector>     // For the vector (like a resizable list)
#include <cstdlib>    // For rand() and srand()
#include <ctime>      // For time() — used to seed the random number

// ============================================================
//  HELPER FUNCTION: replacePlaceholder
// ============================================================
// This function takes a template string like:
//   "{name}'s dog ate the homework."
// and swaps {name} for the actual student name, giving:
//   "Alex's dog ate the homework."
//
// Parameters:
//   excuseTemplate — the original string with {name} in it
//   name           — the real name to insert
// Returns:
//   A new string with {name} replaced by the actual name
// ============================================================
std::string replacePlaceholder(std::string excuseTemplate, const std::string& name) {
    std::string placeholder = "{name}"; // This is what we're looking for

    // find() searches the string and returns the position of {name}.
    // If it's not found, it returns std::string::npos (a special "not found" value).
    size_t position = excuseTemplate.find(placeholder);

    // Only replace if the placeholder was actually found
    if (position != std::string::npos) {
        // replace(start_position, how_many_chars_to_remove, new_text)
        excuseTemplate.replace(position, placeholder.length(), name);
    }

    return excuseTemplate; // Return the updated string
}

// ============================================================
//  MAIN FUNCTION — where the program starts running
// ============================================================
int main() {

    // ----------------------------------------------------------
    // STEP 1: Seed the random number generator
    // ----------------------------------------------------------
    // srand() initializes the random engine.
    // time(0) gives the current time in seconds — it's always
    // different, so we get a new random result every run.
    // Without this, rand() would return the same numbers every time!
    srand(static_cast<unsigned int>(time(0)));

    // ----------------------------------------------------------
    // STEP 2: Store excuse templates in a vector
    // ----------------------------------------------------------
    // A vector is like a dynamic array — it can hold many items.
    // Each item here is a string (one excuse template).
    // {name} is a placeholder we'll replace with the real name later.
    std::vector<std::string> excuses = {
        "{name}'s homework was classified as a national secret and confiscated by the government.",
        "{name} completed the homework, but it gained sentience and ran away.",
        "A time traveler from the future warned {name} that submitting this homework would cause a paradox.",
        "{name}'s printer ran out of ink, so they tried to submit it in invisible ink. It worked too well.",
        "According to {name}'s calculations, the homework exists — just in a parallel universe.",
        "{name}'s dog didn't eat it. The dog enrolled in the class and submitted it as their own.",
        "{name} accidentally uploaded the homework to NASA instead of the student portal.",
        "The homework is done, but {name}'s little sibling used it to build a very impressive paper fortress.",
        "{name} was abducted by aliens who were so impressed by the homework they kept it as a specimen.",
        "{name} spilled coffee on it, and it evolved into a sentient being that is now {name}'s roommate.",
        "A wizard appeared to {name} and said the homework contained a dangerous spell. It had to be burned.",
        "{name} stored the homework in the cloud, but it literally rained and the file got wet.",
        "Due to a glitch in the simulation, {name}'s homework folder has 0 bytes and infinite files.",
        "{name} finished it at exactly midnight and it vanished — possibly due to the Cinderella clause.",
        "The homework was submitted, but the school's email server sent it to 1994 by mistake.",
    };

    // ----------------------------------------------------------
    // STEP 3: Display the welcome banner
    // ----------------------------------------------------------
    std::cout << "============================================" << std::endl;
    std::cout << "   📚  Homework Excuse Generator  📚       " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "  Crafting excuses since the dawn of time. " << std::endl;
    std::cout << "============================================" << std::endl;

    // ----------------------------------------------------------
    // STEP 4: Ask for the student's name
    // ----------------------------------------------------------
    std::string studentName;
    std::cout << "\nEnter the student's name: ";

    // std::getline reads the entire line, including spaces.
    // This is better than cin >> because "John Smith" would work too.
    std::getline(std::cin, studentName);

    // If the user just pressed Enter without typing anything, use a default
    if (studentName.empty()) {
        studentName = "The Student";
    }

    // ----------------------------------------------------------
    // STEP 5: Pick a random excuse
    // ----------------------------------------------------------
    // rand() returns a large random integer.
    // Using % (modulo) with the size of the vector keeps the
    // result within valid index range (0 to size-1).
    //
    // Example: rand() = 83, excuses.size() = 15
    //          83 % 15 = 8  →  we pick index 8
    int randomIndex = rand() % excuses.size();

    // Retrieve the chosen excuse template
    std::string selectedExcuse = excuses[randomIndex];

    // ----------------------------------------------------------
    // STEP 6: Replace {name} with the student's actual name
    // ----------------------------------------------------------
    std::string finalExcuse = replacePlaceholder(selectedExcuse, studentName);

    // ----------------------------------------------------------
    // STEP 7: Print the final excuse
    // ----------------------------------------------------------
    std::cout << "\n--------------------------------------------" << std::endl;
    std::cout << "📝 Excuse generated for: " << studentName      << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "\n  \"" << finalExcuse << "\"\n"               << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "⚠️  Use responsibly. We are not liable for"   << std::endl;
    std::cout << "   any failed classes or suspicious teachers." << std::endl;
    std::cout << "============================================"  << std::endl;

    return 0; // Returning 0 tells the OS the program ran successfully
}
