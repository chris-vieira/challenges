#include <cstdlib>
#include <string>
#include <iostream>
#include <regex>
#include <curl/curl.h>
#include "json.hpp"

int main (int argc, char *argv[]) {

    char users_url[] = "https://jsonplaceholder.typicode.com/users";
    char posts_url[] = "https://jsonplaceholder.typicode.com/posts";
    
    if (argc > 2) {
        std::cerr << "error: wrong number of arguments!" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    CURL *curl;
    std::string readbuff;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argc == 1 ? users_url : posts_url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,  
            +[](void *buffer, size_t size, size_t nmemb, void *userp) -> size_t {
                ((std::string*)userp)->append((char*)buffer, size * nmemb);
                return size * nmemb;
        });
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readbuff);
        (void)curl_easy_perform(curl);
            curl_easy_cleanup(curl);

        if (argc == 1) { // Displays user information in an unformatted (deserialized) way:
            try {
                auto jdata = nlohmann::json::parse(readbuff);
                for (auto u : jdata) {
                    std::cout << "name: " << u["name"] << std::endl;
                    std::cout << "username: " << u["username"] << std::endl;
                    std::cout << "email: " << u["email"] << std::endl;

                    std::cout << "address: " << std::endl << "  " \
                        << "street: " << u["address"]["street"] << std::endl;
                    std::cout << "  " << "suite: " << u["address"]["suite"] << std::endl;
                    std::cout << "  " << "city: " << u["address"]["city"] << std::endl;
                    std::cout << "  " << "zipcode: " << u["address"]["zipcode"] << std::endl;
                    std::cout << "  geo: " << std::endl << "    " \
                        << "lat: " << u["address"]["geo"]["lat"] << std::endl;
                    std::cout << "    " << "long: " << u["address"]["geo"]["lng"] << std::endl;

                    std::cout << "phone: "   << u["phone"] << std::endl;
                    std::cout << "website: " << u["website"] << std::endl;

                    std::cout << "company: " << std::endl << "  " \
                        << "name: " << u["company"]["name"] << std::endl;
                    std::cout << "  " << "catchPhrase: " << u["company"]["catchPhrase"] << std::endl;
                    std::cout << "  " << "bs: " << u["company"]["bs"] << std::endl;
      
                    std::cout << std::endl;
                }
            } catch (const std::exception &e) {
                std::cerr << "error: something nasty occorred in json parser: "  
                    << e.what() << std::endl;
            }            
        } else {         // From a given 'userId', show 'title' and 'body' message:
            std::string::size_type sz;  
            int user_id = std::stoi(argv[1], &sz);
            if (user_id < 0) {
                std::cerr << "error: user id should be non-negative!" << std::endl;
                std::exit(EXIT_FAILURE);
            }

            try {
                auto jdata = nlohmann::json::parse(readbuff);
                for (auto p : jdata) {
                    if (p["userId"] == user_id) {
                        std::cout << "title: " << p["title"] << std::endl;
                        std::cout << "body: "  << p["body"] << std::endl;
                        std::cout << std::endl;
                    }
                }
            } catch (const std::exception &e) {
                std::cerr << "error: something nasty occorred in json parser: "  
                    << e.what() << std::endl;
            }            
        }
    } else {
        std::cerr << "error: something wrong in curl initialization!" 
            << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::exit(EXIT_SUCCESS);
}
