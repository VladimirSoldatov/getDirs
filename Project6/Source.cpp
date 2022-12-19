#include <filesystem>
#include<fstream>
#include <iostream>

using namespace std;
namespace fs = filesystem;

vector<string> getDirectiries(const fs::path& dir, const vector<string>& ext)
{
	vector<string> files;
	for (auto& p : fs::recursive_directory_iterator(dir))
	{
		if (fs::is_regular_file(p))
		{
			if (ext.empty() || find(ext.begin(), ext.end(), p.path().extension().string() )!= ext.end())
			{
				files.push_back(p.path().string());

			}
		}

	}
	return files;
}
int main()
{ 
	auto currnt_path = fs::current_path();
	cout << currnt_path;
	auto root_path = fs::path("/");
	auto space = fs::space(root_path);
	cout << endl;
	cout << "Total        :" << space.capacity/1024/1024/1024<<" Gb" << endl;
	cout << "Busy         :" << space.available/1024/1024/1024 <<" Gb" << endl;
	cout << "Free         :" << space.free/1024/1024/1024 <<" Gb" << endl;
	cout << "Separator is ";
	auto sep = fs::path::preferred_separator;
	printf("%c", sep);

	fs::remove_all(currnt_path/"temp");
	vector<string> dir;

	auto dirs = getDirectiries(currnt_path, dir);
	for (auto item : dirs)
	{
		cout << item << endl;
	}


	return 0;
}