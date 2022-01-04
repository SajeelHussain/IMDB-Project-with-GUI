

// Including libararies to use in program.

#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iterator>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store movie data in a linked list.
struct Movienode
{
public:
    // all variables to store movie data.
    string movietitle;
    string genres;
    string title_year;
    string imdb_score;
    string director_name;
    string director_facebook_likes;
    string num_critic_for_reviews;
    string duration;
    string actor_1_name;
    string actor_1_facebook_likes;
    string actor_2_name;
    string actor_2_facebook_likes;
    string actor_3_name;
    string actor_3_facebook_likes;
    string gross;
    string num_voted_users, cast_total_facebook_likes;
    string facenumber_in_poster;
    string plot_keywords;
    string movie_imdb_link;
    string num_user_for_reviews;
    string language;
    string country;
    string content_rating;
    string budget;
    string aspect_ratio;
    string movie_facebook_likes;
    string color;

    Movienode* next;

    // making node and storing data.
    Movienode(string movietitle,
        string genres,
        string title_year,
        string imdb_score,
        string director_name,
        string director_facebook_likes,
        string num_critic_for_reviews,
        string duration,
        string actor_1_name,
        string actor_1_facebook_likes,
        string actor_2_name,
        string actor_2_facebook_likes,
        string actor_3_name,
        string actor_3_facebook_likes,
        string gross,
        string num_voted_users,
        string cast_total_facebook_likes,
        string facenumber_in_poster,
        string plot_keywords,
        string movie_imdb_link,
        string num_user_for_reviews,
        string language,
        string country,
        string content_rating,
        string budget,
        string aspect_ratio,
        string movie_facebook_likes,
        string color)
    {
        this->movietitle = movietitle;
        this->genres = genres;
        this->title_year = title_year;
        this->imdb_score = imdb_score;
        this->director_name = director_name;
        this->director_facebook_likes = director_facebook_likes;
        this->num_critic_for_reviews = num_critic_for_reviews;
        this->duration = duration;
        this->actor_1_name = actor_1_name;
        this->actor_1_facebook_likes = actor_1_facebook_likes;
        this->actor_2_name = actor_2_name;
        this->actor_2_facebook_likes = actor_2_facebook_likes;
        this->actor_3_name = actor_3_name;
        this->actor_3_facebook_likes = actor_3_facebook_likes;
        this->gross = gross;
        this->num_voted_users = num_voted_users;
        this->cast_total_facebook_likes = cast_total_facebook_likes;
        this->facenumber_in_poster = facenumber_in_poster;
        this->plot_keywords = plot_keywords;
        this->movie_imdb_link = movie_imdb_link;
        this->num_user_for_reviews = num_user_for_reviews;
        this->language = language;
        this->country = country;
        this->content_rating = content_rating;
        this->budget = budget;
        this->aspect_ratio = aspect_ratio;
        this->movie_facebook_likes = movie_facebook_likes;
        this->color = color;
        next = NULL;
    }
}; // end of structure.

// class movie collection
// We implemented different functions related to movie in this class.

class Moviecollection
{

public:
    // head and tail pointer.
    Movienode* head, * tail;
    Moviecollection()
    {
        head = NULL;
        tail = NULL;
    }

    // adding data to the linkedlist after parsing from csv file.
    void add(string movietitle,
        string genres,
        string title_year,
        string imdb_score,
        string director_name,
        string director_facebook_likes,
        string num_critic_for_reviews,
        string duration,
        string actor_1_name,
        string actor_1_facebook_likes,
        string actor_2_name,
        string actor_2_facebook_likes,
        string actor_3_name,
        string actor_3_facebook_likes,
        string gross,
        string num_voted_users,
        string cast_total_facebook_likes,
        string facenumber_in_poster,
        string plot_keywords,
        string movie_imdb_link,
        string num_user_for_reviews,
        string language,
        string country,
        string content_rating,
        string budget,
        string aspect_ratio,
        string movie_facebook_likes,
        string color)
    {
        Movienode* newnode = new Movienode(movietitle,
            genres,
            title_year,
            imdb_score,
            director_name,
            director_facebook_likes,
            num_critic_for_reviews,
            duration,
            actor_1_name,
            actor_1_facebook_likes,
            actor_2_name,
            actor_2_facebook_likes,
            actor_3_name,
            actor_3_facebook_likes,
            gross,
            num_voted_users,
            cast_total_facebook_likes,
            facenumber_in_poster,
            plot_keywords,
            movie_imdb_link,
            num_user_for_reviews,
            language,
            country,
            content_rating,
            budget,
            aspect_ratio,
            movie_facebook_likes,
            color);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    };


    // function to search movies yearwise.
    string searchByYear(string input)
    {
        bool found = false;
        Movienode* temp;
        temp = head;
        while (temp != NULL)
        {
            if (temp->title_year == input)
            {
                cout << "---------------------------------------Movie Data ----------------------------------------" << endl;
                string output = "";
                cout << "movie title = " << temp->movietitle << endl;
                cout << "genres = " << temp->genres << endl;
                cout << "title year = " << temp->title_year << endl;
                cout << "imdb score = " << temp->imdb_score << endl;
                cout << "Director = " << temp->director_name << endl;
                cout << "Director Facebook likes = " << temp->director_facebook_likes << endl;
                cout << "Critic Reviews = " << temp->num_critic_for_reviews << endl;
                cout << "Duration = " << temp->duration << endl;
                cout << "Main Actor = " << temp->actor_1_name << endl;
                cout << "Actor likes= " << temp->actor_1_facebook_likes << endl;
                cout << "Co_actor = " << temp->actor_2_name << endl;
                cout << "Co-actor likes = " << temp->actor_2_facebook_likes << endl;
                cout << "Second Co-Actor = " << temp->actor_3_name << endl;
                cout << "Second Co-Actor likes = " << temp->actor_3_facebook_likes << endl;
                cout << "Gross = " << temp->gross << endl;
                cout << "Num of voted user = " << temp->num_voted_users << endl;
                cout << "Cast facebook likes = " << temp->cast_total_facebook_likes << endl;
                cout << endl;
                cout << "-----------------------------------------------------------------------------------------";
                cout << endl;
                output = output + temp->movietitle + "\n";
                output = output + temp->genres + "\n";
                output = output + temp->title_year + "\n";
                output = output + temp->imdb_score + "\n";
                output = output + temp->director_name + "\n";
                output = output + temp->director_facebook_likes + "\n";
                output = output + temp->num_critic_for_reviews + "\n";
                output = output + temp->duration + "\n";
                output = output + temp->actor_1_name + "\n";
                output = output + temp->actor_1_facebook_likes + "\n";
                output = output + temp->actor_2_name + "\n";
                output = output + temp->actor_2_facebook_likes + "\n";
                output = output + temp->actor_3_name + "\n";
                output = output + temp->actor_3_facebook_likes + "\n";
                output = output + temp->gross + "\n";
                output = output + temp->num_voted_users + "\n";
                output = output + temp->cast_total_facebook_likes + "\n";
                output = output + temp->facenumber_in_poster + "\n";
                output = output + temp->plot_keywords + "\n";
                output = output + temp->movie_imdb_link + "\n";
                output = output + temp->num_user_for_reviews + "\n";
                output = output + temp->language + "\n";
                output = output + temp->country + "\n";
                output = output + temp->content_rating + "\n";
                output = output + temp->budget + "\n";
                output = output + temp->aspect_ratio + "\n";
                output = output + temp->movie_facebook_likes + "\n";
                output = output + temp->color + "\n";
                found = true;
                return output;
            }
            temp = temp->next;
        }
        if (found == false)
        {
            cout << "The given movie is not in the database. " << endl;
        }
    }

    // function to search movies by genre.
    void SearchGen()
    {
        bool found = false;
        Movienode* temp;
        temp = head;
        string input;
        cout << "\nEnter the movie genre: ";
        getline(cin, input);
        cout << "\n"
            << endl;
        while (temp != NULL && temp->movietitle != "")
        {
            size_t fnd = temp->genres.find(input);
            if (fnd != string::npos)
            {
                cout << "Director Name: " << temp->director_name << endl;
                cout << "Movie Name: " << temp->movietitle << endl;
                found = true;
                cout << "\n"
                    << endl;
            }
            temp = temp->next;
        }

        if (found == false)
        {
            cout << "The given movie is not in the database. " << endl;
        }
    }

    // function to search movie by movie name in the linkedlist.
    string search(string input)
    {
        bool found = false;
        Movienode* temp;
        temp = head;
        while (temp != NULL)
        {
            if (temp->movietitle == input)
            {
                string output = "";
                output = output + temp->movietitle + "\n";
                output = output + temp->genres + "\n";
                output = output + temp->title_year + "\n";
                output = output + temp->imdb_score + "\n";
                output = output + temp->director_name + "\n";
                output = output + temp->director_facebook_likes + "\n";
                output = output + temp->num_critic_for_reviews + "\n";
                output = output + temp->duration + "\n";
                output = output + temp->actor_1_name + "\n";
                output = output + temp->actor_1_facebook_likes + "\n";
                output = output + temp->actor_2_name + "\n";
                output = output + temp->actor_2_facebook_likes + "\n";
                output = output + temp->actor_3_name + "\n";
                output = output + temp->actor_3_facebook_likes + "\n";
                output = output + temp->gross + "\n";
                output = output + temp->num_voted_users + "\n";
                output = output + temp->cast_total_facebook_likes + "\n";
                output = output + temp->facenumber_in_poster + "\n";
                output = output + temp->plot_keywords + "\n";
                output = output + temp->movie_imdb_link + "\n";
                output = output + temp->num_user_for_reviews + "\n";
                output = output + temp->language + "\n";
                output = output + temp->country + "\n";
                output = output + temp->content_rating + "\n";
                output = output + temp->budget + "\n";
                output = output + temp->aspect_ratio + "\n";
                output = output + temp->movie_facebook_likes + "\n";
                output = output + temp->color + "\n";
                found = true;
                return output;
            }
            temp = temp->next;
        }
        if (found == false)
        {
            return "The given movie is not in the database. ";
        }
    }


    // function to find and print the coactors of actor.
    void searchCoactorOfActor(string input)
    {
        bool found = false;
        Movienode* temp;
        temp = head;
        while (temp != NULL)
        {
            if (temp->actor_1_name == input)
            {
                cout << "Movie Title: " << temp->movietitle << endl;
                cout << "Actor: " << temp->actor_1_name << endl;
                cout << "Co Actor: " << temp->actor_2_name << endl;
                cout << "Second Co actor: " << temp->actor_3_name << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (found == false)
        {
            cout << "The given actor is not in the database. " << endl;
        }
    }

    // function to display coactors of a actors.
    bool searchbyactor(string input)
    {
        vector<string> coactor;
        bool found = false;
        Movienode* temp;
        temp = head;
        cout << "Now the actor is " << input << endl;
        if (input == "")
        {
            return false;
        }
        while (temp != NULL)
        {
            if (temp->actor_1_name == input)
            {
                cout << "Co Actor of the actor is : " << temp->actor_2_name << endl;
                cout << "Second Co actor of the actor is : " << temp->actor_3_name << endl;
                searchbyactor(temp->actor_2_name);
                searchbyactor(temp->actor_3_name);

                return true;
            }
            temp = temp->next;
        }
        if (found == false)
        {
            cout << "The Actor " << input << " has no co-actor." << endl;
            return false;
        }
        return false;
    }


    map<string, vector<string>> km; //creating hashmap by using inbuilt library for storing movie data yearwise.

    // function to insert data of movies and their release year in a hashmap.
    void Insert(string year, string movie)

    {
        if (year != "")
        {
            vector<string> vx;
            auto it = km.find(year);

            if (it != km.end())
            {

                (*it).second.push_back(movie);
                km.insert({ year, (*it).second });
            }

            else
            {
                vx.push_back(movie);
                km.insert({ year, vx });
            }

        }
    }

    // function to print movies data yearwise in increasing order.
    void printIncreasingOrder()
    {
        map<string, vector<string>>::iterator it;
        vector<string>::iterator hr;
        for (it = km.begin(); it != km.end(); ++it)
        {

            cout << "Director Name: " << (*it).first << endl;

            cout << "\n---------------------------------------Movieslist---------------------------------------\n"
                << endl;

            for (hr = (*it).second.begin(); hr != (*it).second.end(); ++hr)
            {
                cout << *hr << "   " << endl;
            }

            cout << "\n"
                << endl;
        }
    }


    // function to print movies data yearwise in decreasing order.
    void printDecreasingOrder()
    {
        map<string, vector<string>>::reverse_iterator it;
        vector<string>::iterator hr;
        for (it = km.rbegin(); it != km.rend(); ++it)
        {

            cout << "Director Name: " << (*it).first << endl;

            cout << "\n---------------------------------------Movieslist---------------------------------------\n"
                << endl;

            for (hr = (*it).second.begin(); hr != (*it).second.end(); ++hr)
            {
                cout << *hr << "   " << endl;
            }

            cout << "\n"
                << endl;
        }
    }


    map<string, vector<string>> rm; // declaring hashmap to store movie name and its rating.

    // inserting movies rating(key) and name(value) in the hashmap.

    void InsertRating(string rating, string movie)
    {
        if (rating != "")
        {
            vector<string> vx;
            auto it = rm.find(rating);

            if (it != rm.end())
            {

                (*it).second.push_back(movie);
                rm.insert({ rating, (*it).second });
            }

            else
            {
                vx.push_back(movie);
                rm.insert({ rating, vx });
            }

        }
    }

    // print movies data fron the hashmap based on rating.
    void printRatingwise()
    {
        map<string, vector<string>>::reverse_iterator it;
        vector<string>::iterator hr;
        for (it = rm.rbegin(); it != rm.rend(); ++it)
        {

            cout << "Rating: " << (*it).first << endl;

            cout << "\n---------------------------------------Movieslist---------------------------------------\n"
                << endl;

            for (hr = (*it).second.begin(); hr != (*it).second.end(); ++hr)
            {
                cout << *hr << "   " << endl;
            }

            cout << "\n"
                << endl;
        }
    }

    map<string, map<string, vector<string>>> rrm; //hashmaps to store genre,rating and movie details.

    // function to insert data into the hashmap.

    void InsertMovierating(string genre, string rating, string movie)
    {
        map<string, vector<string>> kjh;
        vector<string> vx;
        auto it2 = rrm.find(genre);
        if (it2 != rrm.end())
        {
            auto it = (*it2).second.find(rating);

            if (it != kjh.end())
            {

                (*it).second.push_back(movie);
                kjh.insert({ rating, (*it).second });
            }

            else
            {
                vx.push_back(movie);
                kjh.insert({ rating, vx });
            }

            rrm.insert({ genre, kjh });

        }

        else
        {
            vx.push_back(movie);
            kjh.insert({ rating, vx });

            rrm.insert({ genre, kjh });

        }
    }


    //
    void printGenre()
    {
        string gen;
        cout << "Enter Genre: ";
        getline(cin, gen);
        map<string, vector<string>>::iterator it;
        vector<string>::iterator hr;

        auto it3 = rrm.find(gen);

        if (it3 != rrm.end())
        {
            cout << "Movie Genre: " << (*it3).first << endl;

            for (it = (*it3).second.begin(); it != (*it3).second.end(); ++it)
            {

                cout << "Rating: " << (*it).first << endl;

                cout << "\n---------------------------------------Movieslist---------------------------------------\n"
                    << endl;

                for (hr = (*it).second.begin(); hr != (*it).second.end(); ++hr)
                {
                    cout << *hr << "   " << endl;
                }

                cout << "\n"
                    << endl;
            }
        }

        else
        {
            cout << "Not Found Such Type of genre" << endl;
        }
    }

    string returnHashmapOfCoActor(string input)
    {

        bool found = false;
        Movienode* temp;
        temp = head;

        while (temp != NULL)
        {
            if (temp->movietitle == input)
            {
                cout << "Movie Title: " << temp->movietitle << endl;
                cout << "Actor: " << temp->actor_1_name << endl;
                cout << "Co Actor: " << temp->actor_2_name << endl;
                cout << "Second Co actor: " << temp->actor_3_name << endl;
                found = true;
            }
            temp = temp->next;
        }
        if (found == false)
        {
            cout << "The given movie is not in the database. " << endl;
        }
        return temp->actor_1_name;
    }
};

class DirectorNode
{
private:
    map<string, vector<string>> g;

public:
    void Insert(string name, string movie)

    {
        vector<string> vx;
        auto it = g.find(name);

        if (it != g.end())
        {

            (*it).second.push_back(movie);
            g.insert({ name, (*it).second });
        }

        else
        {
            vx.push_back(movie);
            g.insert({ name, vx });
        }

    }

    void print()
    {
        map<string, vector<string>>::iterator it;
        vector<string>::iterator hr;
        for (it = g.begin(); it != g.end(); ++it)
        {

            cout << "Director Name: " << (*it).first << endl;

            cout << "\n---------------------------------------Movieslist---------------------------------------\n"
                << endl;

            for (hr = (*it).second.begin(); hr != (*it).second.end(); ++hr)
            {
                cout << *hr << "   " << endl;
            }

            cout << "\n"
                << endl;
        }
    }

    void Search()
    {

        string sname;
        cout << "\n\nEnter Name of Director to Search: ";
        getline(cin, sname);
        vector<string>::iterator hr;

        auto it = g.find(sname);
        if (it != g.end())
        {

            cout << "\n---------------------------------------Movieslist---------------------------------------\n"
                << endl;

            for (hr = (*it).second.begin(); hr != (*it).second.end(); ++hr)
            {
                cout << *hr << "   " << endl;
            }

            cout << "\n"
                << endl;
        }
        else
        {
            cout << "Not Found in the list." << endl;
        }
    }
};

class Actorlist
{

public:
    map<string, map<string, vector<string>>> rrm;

    void Insert(string actor_name, string movies, string year)

    {
        map<string, vector<string>> kjh;
        vector<string> vx;

        auto it2 = rrm.find(actor_name);
        if (it2 != rrm.end())
        {
            vx.push_back(year);
            (*it2).second.insert({ movies, vx });
        }

        else
        {
            vx.push_back(year);
            kjh.insert({ movies, vx });

            rrm.insert({ actor_name, kjh });

        }
    }

    void Search()
    {
        string gen;
        cout << "Enter Name: ";
        getline(cin, gen);
        map<string, vector<string>>::iterator it;
        vector<string>::iterator hr;

        auto it3 = rrm.find(gen);

        if (it3 != rrm.end())
        {
            cout << "\nActorName : " << (*it3).first << endl;

            for (it = (*it3).second.begin(); it != (*it3).second.end(); ++it)
            {
                if ((*it).first != "")
                {
                    cout << "Movie: " << (*it).first << endl;
                }
                else
                {
                    continue;
                }

                for (hr = (*it).second.begin(); hr != (*it).second.end(); ++hr)
                {
                    cout << "Year: " << *hr << "   " << endl;
                    break;
                }

                cout << "\n"
                    << endl;
            }
        }

        else
        {
            cout << "Not Such Actor found" << endl;
        }
    }

    vector<string> returnmovieslist()
    {
        vector<string> movielist;
        string gen;
        cout << "Enter Name: ";
        getline(cin, gen);
        map<string, vector<string>>::iterator it;
        vector<string>::iterator hr;

        auto it3 = rrm.find(gen);

        if (it3 != rrm.end())
        {

            for (it = (*it3).second.begin(); it != (*it3).second.end(); ++it)
            {
                if ((*it).first != "")
                {
                    cout << "Movie: " << (*it).first << endl;
                    movielist.push_back((*it).first);
                }
                else
                {
                    continue;
                }

                for (hr = (*it).second.begin(); hr != (*it).second.end(); ++hr)
                {
                    break;
                }

                cout << "\n"
                    << endl;
            }
        }

        else
        {
            cout << "Not Such Actor found" << endl;
        }
        return movielist;
    }
};

class movie
{
public:
    Moviecollection collection;
    DirectorNode dir;
    Actorlist actor;

    vector<string> movielist2;
    vector<string> coactorVector;
    string coactor;

    string line = "";
    int count = 0;
    string movietitle;
    string genres;
    string title_year;
    string imdb_score;
    string director_name;
    string director_facebook_likes;
    string num_critic_for_reviews;
    string duration;
    string actor_1_name;
    string actor_1_facebook_likes;
    string actor_2_name;
    string actor_2_facebook_likes;
    string actor_3_name;
    string actor_3_facebook_likes;
    string gross;
    string num_voted_users, cast_total_facebook_likes;
    string facenumber_in_poster;
    string plot_keywords;
    string movie_imdb_link;
    string num_user_for_reviews;
    string language;
    string country;
    string content_rating;
    string budget;
    string aspect_ratio;
    string movie_facebook_likes;
    string color;
    void readdata()
    {

        ifstream inputfile;
        inputfile.open("D:\\Sajeel\\sajeel\\Release\\IMDB_Top5000-SEECS.csv");
        if (inputfile.is_open())
        {

            while (!inputfile.eof())
            {
                if (count == 0)
                {
                    string temp;
                    getline(inputfile, temp);
                    count = 1;
                }
                else
                {
                    getline(inputfile, movietitle, ',');
                    getline(inputfile, genres, ',');
                    getline(inputfile, title_year, ',');
                    getline(inputfile, imdb_score, ',');
                    getline(inputfile, director_name, ',');
                    getline(inputfile, director_facebook_likes, ',');
                    getline(inputfile, num_critic_for_reviews, ',');
                    getline(inputfile, duration, ',');
                    getline(inputfile, actor_1_name, ',');
                    getline(inputfile, actor_1_facebook_likes, ',');
                    getline(inputfile, actor_2_name, ',');
                    getline(inputfile, actor_2_facebook_likes, ',');
                    getline(inputfile, actor_3_name, ',');
                    getline(inputfile, actor_3_facebook_likes, ',');
                    getline(inputfile, gross, ',');
                    getline(inputfile, num_voted_users, ',');
                    getline(inputfile, cast_total_facebook_likes, ',');
                    getline(inputfile, facenumber_in_poster, ',');
                    getline(inputfile, plot_keywords, ',');
                    getline(inputfile, movie_imdb_link, ',');
                    getline(inputfile, num_user_for_reviews, ',');
                    getline(inputfile, language, ',');
                    getline(inputfile, country, ',');
                    getline(inputfile, content_rating, ',');
                    getline(inputfile, budget, ',');
                    getline(inputfile, aspect_ratio, ',');
                    getline(inputfile, movie_facebook_likes, '\n');

                    collection.add(movietitle, genres, title_year, imdb_score, director_name, director_facebook_likes, num_critic_for_reviews, duration, actor_1_name, actor_1_facebook_likes, actor_2_name, actor_2_facebook_likes, actor_3_name, actor_3_facebook_likes, gross, num_voted_users, cast_total_facebook_likes, facenumber_in_poster, plot_keywords, movie_imdb_link, num_user_for_reviews, language, country, content_rating, budget, aspect_ratio, movie_facebook_likes, color);
                    dir.Insert(director_name, movietitle);
                    collection.Insert(title_year, movietitle);
                    actor.Insert(actor_1_name, movietitle, title_year);
                }
            }
        }
    }
    string searchInMovieCollection(string moviename)
    {
        return collection.search(moviename);
    }

    void printDir()
    {
        dir.print();
    }

    void searchDir()
    {
        dir.Search();
    }

    void searchactor()
    {
        actor.Search();
    }
    void returnMovieListAfActor()
    {
        movielist2 = actor.returnmovieslist();
    }

    void SearchProfileOfActor()
    {
        vector<string>::iterator hr;
        cout << "The list of co-actor of : " << endl;
        for (hr = movielist2.begin(); hr != movielist2.end(); ++hr)
        {
            collection.searchCoactorOfActor(*hr);
            cout << endl;
        }
    }
    void SearchProfileOfUniqueActor()
    {
        vector<string>::iterator hr;
        cout << "The list of co-actor of : " << endl;
        for (hr = movielist2.begin(); hr != movielist2.end(); ++hr)
        {
            collection.searchCoactorOfActor(*hr);
            cout << endl;
        }
    }
    void returnHashMapOfCoactor()
    {
        vector<string>::iterator hr;
        for (hr = movielist2.begin(); hr != movielist2.end(); ++hr)
        {
            coactor = collection.returnHashmapOfCoActor(*hr);
            cout << endl;
            coactorVector.push_back(coactor);
        }

        auto ip = unique(coactorVector.begin(), coactorVector.end());

        coactorVector.resize(distance(coactorVector.begin(), ip));

        for (ip = coactorVector.begin(); ip != coactorVector.end(); ++ip)
        {
            cout << *ip << endl;
        }
    }

    void searchCoactorofanActor()
    {
        string actor;
        cout << "\n Enter Actor to find its coactors: ";
        getline(cin, actor);
        collection.searchCoactorOfActor(actor);
    }
    void Searchcoactorofcoactor() {}

    void Gen()
    {
        collection.SearchGen();
    }

    void printYearwise()
    {
        collection.printIncreasingOrder();
    }

    void printYearwise2()
    {
        collection.printDecreasingOrder();
    }

    string searhbyYear(string year)
    {
        return collection.searchByYear(year);
    }

    void printRating()
    {
        collection.printRatingwise();
    }

    void searchCoActorofActor()
    {
        string actor;
        cout << "\n Enter Actor to find its coactors of its coactors: ";
        getline(cin, actor);
        collection.searchbyactor(actor);
    }
};

//int main()
//{
//    movie moviedata;
//
//    moviedata.readdata();
//    moviedata.searchDir();
//    moviedata.Gen();
//
//    moviedata.searchInMovieCollection();
//    moviedata.searhbyYear();
//
//    moviedata.printYearwise();
//    moviedata.printYearwise2();
//
//    moviedata.Gen();
//    moviedata.printRating();
//
//    moviedata.searchactor();
//
//    moviedata.searchCoActorofActor();
//
//
//}


//int main()
//{
//    movie moviedata;
//    DirectorNode dn;
//
//    do
//    {
//        cout << "What kind of operations would you like to execute: " << endl;
//        cout << "1) Related to Movies" << endl;
//        cout << "2) Related to Actors" << endl;
//        cout << "3) Related to Diractors" << endl;
//        cout << "Enter your choice: ";
//        int firstchoice;
//        cin >> firstchoice;
//        switch (firstchoice)
//        {
//        case 1:
//            cout << "Functions Related to movies are: " << endl;
//            cout << "\t1) Search and print all details of a movie." << endl;
//            cout << "\t2) Print all movies in a particular year." << endl;
//            cout << "\t3) Print all movies with a particular rating." << endl;
//            cout << "Enter your choice: ";
//            int secondchoice;
//            cin >> secondchoice;
//            switch (secondchoice)
//            {
//            case 1:
//                moviedata.searchInMovieCollection();
//                break;
//            case 2:
//                break;
//
//            case 3:
//                break;
//            default:
//                cout << "INPUT A NUMBER BETWEEEN 0 AND 13\n";
//            }
//            break;
//        case 2:
//            break;
//        }
//    } while (true);
//}


#pragma once

namespace sajeel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(70, 153);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(166, 29);
			this->textBox1->TabIndex = 0;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(268, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(189, 117);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::CornflowerBlue;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::CornflowerBlue;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(85, 219);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 35);
			this->button1->TabIndex = 2;
			this->button1->Text = L"READ";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::CornflowerBlue;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Location = System::Drawing::Point(85, 282);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 35);
			this->button2->TabIndex = 3;
			this->button2->Text = L"SEARCH";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::CornflowerBlue;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Location = System::Drawing::Point(85, 343);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(130, 35);
			this->button3->TabIndex = 4;
			this->button3->Text = L"SEARCH BY YEAR";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->AutoScrollMargin = System::Drawing::Size(10, 10);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(379, 153);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(340, 377);
			this->panel1->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AccessibleRole = System::Windows::Forms::AccessibleRole::ScrollBar;
			this->label1->AutoEllipsis = true;
			this->label1->AutoSize = true;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 7;
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Movie";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		msclr::interop::marshal_context context;
        movie mov;
        mov.readdata();
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
    msclr::interop::marshal_context context;
	movie mov;
    mov.readdata();
	label1->Text = context.marshal_as<String^>(mov.searchInMovieCollection(context.marshal_as<string>(textBox1->Text)));
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;
	movie mov;
	mov.readdata();
	label1->Text = context.marshal_as<String^>(mov.searhbyYear(context.marshal_as<string>(textBox1->Text)));
}
};
}
