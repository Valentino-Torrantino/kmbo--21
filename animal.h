#include <iostream>
#include <cstring>
#include <sstream>


class Animal {
private:
	float average_wieght; //  вес
public:
	void set_average_wieght(float new_average_wieght) { average_wieght = new_average_wieght; }
	float get_average_wieght() const { return average_wieght; }

	string Animal_color ;
	virtual string about() const;
};

class Mammal : public Animal {
private:
	int lifetime; // время
public:
	void set_lifetime(int new_lifetime) { lifetime = new_lifetime; }
	int get_lifetime() const { return lifetime; }

     bool gender;
	virtual string about() const;
};

class Predator : public Mammal {
private:
	float average_number_of_teeth; //  кол-во зубов
public:
	void set_average_number_of_teeth(float new_average_number_of_teeth) { average_number_of_teeth = new_average_number_of_teeth; }
	float get_average_number_of_teeth() const { return average_number_of_teeth; }

	bool omnivorous;
	virtual string about() const;
};

class Whales : public Mammal {
private:
	int average_sailed_distance_per_season; // расстояние
public:
	void set_average_sailed_distance_per_season(int new_average_sailed_distance_per_season) { average_sailed_distance_per_season = new_average_sailed_distance_per_season; 
	}
	int get_average_sailed_distance_per_season() const { return average_sailed_distance_per_season; }


	bool opportunity_to_get_out_of_the_water;
	virtual string about() const;
};

class Dog : public Mammal {
private:
	int maximum_speed;
public:
	void set_maximum_speed(int new_maximum_speed) { maximum_speed = new_maximum_speed; }
	int get_maximum_speed() const { return maximum_speed; }


	float Tail_length;
	virtual string about() const;
};

class Husky : public Dog {
private:
	string eye_color;
public:
	void set_eye_color(string new_eye_color) { eye_color = new_eye_color; }
	string get_eye_color() const { return eye_color; }

	float Average_length_of_wool;
	virtual string about() const;
};

class Pug : public Dog {
private:
	int coat_length;
public:
	void set_coat_length(int new_coat_length) { coat_length = new_coat_length; }
	int get_coat_length() const { return coat_length; }

	float Leg_length;
	virtual string about() const;
};