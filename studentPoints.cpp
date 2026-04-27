#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
struct student {
	std::string name;
	std::string points;
};
void separate(std::vector<student>& students, std::string data) {
	std::stringstream partData(data);
	std::string part;
	std::stack<char> brackets;
	bool newPart = false;
	std::string partRecursion = "";
	while(getline(partData, part)) {
		for(int i = 0; i < part.length(); i++) {
			if(part[i] == '{') {
				newPart = true;
				brackets.push('{');
			}
			if(newPart) {
				partRecursion += part[i];
			}
			if(part[i] == '}') {
				if(!brackets.empty()) {
					brackets.pop();
				}
			}
			if(newPart && brackets.empty()) {
				int j = 0;
				student s;
				int first= 0;
				int end = 0;
				while(j < partRecursion.length()) {
					if(partRecursion[j] == ':') {
						first = j;
						end = 0;
					}
					end++;
					if(partRecursion[j] == ',') {
						s.name = partRecursion.substr(first + 3, end - 5);
						break;
					}
					j++;
				}
				while (j < partRecursion.length() and partRecursion[j] != ':'){
				    j++;
				}
				first = j + 2;
				while (j < partRecursion.length() and partRecursion[j] != ',' and partRecursion[j] != '}'){
				    j++;
				}
				s.points = partRecursion.substr(first, j - first);
				students.push_back(s);
				if (partRecursion.size() > 2) {
					separate(students, partRecursion.substr(1, partRecursion.size() - 2));
				}
				partRecursion = "";
				newPart = false;
			}


		}
		if(newPart) {
			partRecursion += '\n';
		}
	}
}
int main()
{
	std::string data = R"(
     [
       {
         "fullName": "John Smith",
         "points": 20,
         "child": {
           "fullName": "Michael Brown",
           "points": 25,
           "child": {
             "fullName": "David Wilson",
             "points": 14
           }
         }
       },
       {
         "fullName": "Emma Johnson",
         "points": 30
       },
       {
         "fullName": "Olivia Davis",
         "points": 22,
         "child": {
           "fullName": "James Miller",
           "points": 18
         }
       }
     ]
 )";
	std::vector<student> students;
	separate(students, data);
	double sum = 0;
	double count = students.size();
	std::cout << "Students name: " << std::endl;
	for(int i = 0; i < count; i++) {
		std::cout << students[i].name << std::endl;
		sum += std::stoi(students[i].points);
	}
	std::cout << std::endl;
	std::cout << "Average: " << sum / count;
	
	return 0;
}