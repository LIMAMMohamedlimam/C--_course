#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to create a text-only post
void createPost(const string& text) {
    cout << "--- Text Post ---" << endl;
    cout << "Text: " << text << endl;
    cout << "-----------------" << endl;
}

// Function to create a text and image post
void createPost(const string& text, const string& image) {
    cout << "--- Text and Image Post ---" << endl;
    cout << "Text: " << text << endl;
    cout << "Image: " << image << endl;
    cout << "-------------------------" << endl;
}

// Function to create a text, image, and hashtags post
void createPost(const string& text, const string& image, const vector<string>& hashtags) {
    cout << "--- Text, Image, and Hashtags Post ---" << endl;
    cout << "Text: " << text << endl;
    cout << "Image: " << image << endl;
    cout << "Hashtags: ";
    if (hashtags.empty())
    {
        cout << "No hashtags" << endl;
    }
    else
    {
        for (const string& hashtag : hashtags) {
            cout << hashtag << " ";
        }
        cout << endl;
    }
    
    cout << "-----------------------------------" << endl;
}

int main() {
    // Demonstrate creating different types of posts
    cout << "--- Creating Posts ---" << endl;

    // Text-only post
    createPost("Hello, world! This is my first post.");

    // Text and image post
    createPost("Check out this amazing picture!", "image.jpg");

    // Text, image, and hashtags post
    vector<string> hashtags1 = {"#travel", "#nature", "#photography"};
    createPost("Exploring the mountains today!", "mountain_view.png", hashtags1);

    // Text, image, and hashtags post with no hashtags
    vector<string> hashtags2 = {};
    createPost("Just a regular day", "daily.png", hashtags2);

    // User input for creating a post
    int postType;
    cout << "--- Create Your Own Post ---" << endl;
    cout << "Choose post type:" << endl;
    cout << "1. Text-only" << endl;
    cout << "2. Text and image" << endl;
    cout << "3. Text, image, and hashtags" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> postType;

    cin.ignore(); // Consume the newline character left in the buffer

    string text, image, hashtagInput;
    vector<string> hashtags;

    if (postType == 1) {
        cout << "Enter text: ";
        getline(cin, text);
        createPost(text);
    } else if (postType == 2) {
        cout << "Enter text: ";
        getline(cin, text);
        cout << "Enter image name: ";
        getline(cin, image);
        createPost(text, image);
    } else if (postType == 3) {
        cout << "Enter text: ";
        getline(cin, text);
        cout << "Enter image name: ";
        getline(cin, image);
        cout << "Enter hashtags (separated by spaces): ";
        getline(cin, hashtagInput);

        // Parse hashtags from the input string
        string currentHashtag;
        for (char c : hashtagInput) {
            if (c == ' ') {
                if (!currentHashtag.empty()) {
                    hashtags.push_back("#" + currentHashtag);
                    currentHashtag.clear();
                }
            } else {
                currentHashtag += c;
            }
        }
        if (!currentHashtag.empty()) {
            hashtags.push_back("#" + currentHashtag);
        }

        createPost(text, image, hashtags);
    } else {
        cout << "Invalid post type." << endl;
    }

    return 0;
}
