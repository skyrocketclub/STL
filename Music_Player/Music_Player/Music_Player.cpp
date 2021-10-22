// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
    friend std::ostream& operator<<(std::ostream& os, const Song& s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
        : name{ name }, artist{ artist }, rating{ rating } {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }

    bool operator<(const Song& rhs) const {
        return this->name < rhs.name;
    }

    bool operator==(const Song& rhs) const {
        return this->name == rhs.name;
    }
};

std::ostream& operator<<(std::ostream& os, const Song& s) {
    os << std::setw(20) << std::left << s.name
        << std::setw(30) << std::left << s.artist
        << std::setw(2) << std::left << s.rating;
    return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song& song) {
    std::cout << "Curently Playing: " << song.get_name() << " by " <<std::setw(20)<<std::left<< song.get_artist() << "\t\t " << song.get_rating() << "\n";
}

void display_playlist(const std::list<Song>& playlist, const Song& current_song) {

    for (auto elem : playlist) {
        std::cout << elem << std::endl;
    }
    std::cout << "Curent Song: " << std::endl;
    std::cout << current_song << std::endl;
}



int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}
    };

    std::list<Song>::iterator current_song = playlist.begin();

    char option{};
    display_playlist(playlist, *current_song);

    while (option != 'Q') {
        
        display_menu();
        std::cin >> option;
        
        switch (option)
        {
            case 'F':
            {
                auto it = playlist.begin();
                current_song = it;
                play_current_song(*it);
            }
            break;
            case 'N':
            {
                if (*current_song == playlist.back()) {
                    current_song = playlist.begin();
                    play_current_song(*current_song);
                }
                else {
                    current_song++;
                    play_current_song(*current_song);
                }
                
            }
            break;
            //Work On this function...
            case 'P':
            {
                if (current_song != playlist.begin()) {
                    current_song--;
                    play_current_song(*current_song);
                }
                else {
                    current_song = playlist.end();
                    current_song--;
                    play_current_song(*current_song);
                }
            }
            break;
            case 'A':
            {
                std::string name{}, artist{};
                int rating{};

                std::cin.ignore(1, '\n');
                std::cout << "Song Name: ";
                std::getline(std::cin, name);
                std::cout << "Artiste: ";
                std::getline(std::cin, artist);
                std::cout << "Rating: ";
                std::cin >> rating;

              
                Song new_add{ name,artist,rating };
                playlist.emplace(current_song,new_add);
                std::advance(current_song, -1);
                play_current_song(*current_song);
            }
            break;
            case 'L':
            {
                display_playlist(playlist, *current_song);
            }
            break;

            case 'Q':
            {
                option = 'Q';
            }
            break;

            default:
            {
                std::cout << "KINDLY ENTER A VALID INPUT\n";
            }
                break;
        }
    }
   

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}