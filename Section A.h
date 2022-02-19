#pragma once

#include <string>

using namespace std;

class URL{
public:
	URL(const string URL){
		fullURL = URL;

		size_t schemeEnd = URL.find("//");
		scheme = URL.substr(0, schemeEnd);

		size_t authorityEnd = URL.find("/", schemeEnd + 2);
		authority = URL.substr(schemeEnd, authorityEnd - schemeEnd);

		path = URL.substr(authorityEnd);
	}
	//getters 
	string getURL() const {
		return fullURL;
	}
	string getScheme() const {
		return scheme;
	}
	string getAuthority() const {
		return authority;
	}
	string getPath() const {
		return path;
	}
	

private:
	string fullURL;
	string scheme;
	string authority;
	string path;

};


void printURL(const URL& input) {
	cout << input.getURL() << endl;
	cout << input.getScheme() << endl;
	cout << input.getAuthority() << endl;
	cout << input.getPath() << endl;
}

ostream& operator << (ostream& out, const URL& url) {
	out << "URL: " << url.getURL() << "\n" << "Scheme: " << url.getScheme() << "\n" 
		<< "Authority: " << url.getAuthority() << "\n" << "Path: " << url.getPath();
	return out;
}
