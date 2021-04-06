#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <iomanip>

#include <sstream>


using namespace std;
using namespace chrono;


typedef vector<int> vi;

typedef vector<long double> vld;
typedef duration<double> DD;
typedef system_clock::time_point S_C_TP;


class HeapSort{
public:
    void _insert (vi arr){
        for (int i =arr.size()-1; i >=1; --i) {
            insert(arr,1);
        }
    }
    void insert(vi &arr, int size)
    {
        size = size + 1;
        int i = size;
        while (i > 0 && arr[(i - 1) / 2] < arr[i])
        {
            swap(arr[(i - 1) / 2], arr[i]);
            i = (i - 1) / 2;
        }
    }
    void heapfiy(vi &arr)
    {
        int startIdx = (arr.size() / 2) - 1;
        for (int i = startIdx; i >= 0; i--)
        {
            adjust(arr, i);
        }
    }
    void heapSort(vi &arr)
    {

        heapfiy(arr);
        for (int i = arr.size() - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            adjust(arr, 0);
        }
    }

private:
    void adjust(vi &arr, int i)
    {
        int n = arr.size();
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
            largest = l;

        if (r < n && arr[r] > arr[largest])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            adjust(arr, largest);
        }
    }


};









void writeNRandomlyNumbersInFile(int n, fstream &file)
{
    srand(time(nullptr));
    for (int i = 0; i < n; ++i)
    {
        file << rand() << " ";
    }
    file.seekp(ios::beg);
}
vi &getNIntFromFile(const int &n, fstream &File)
{
    vi *input = new vi;
    for (int i = 0; i < n; ++i)
    {
        int tmp;
        File >> tmp;
        input->push_back(tmp);
    }
    return *input;
}




int main()
{
    fstream file("generatednumbers.txt", ios::out);
    fstream jsonfile("data.JSON", ios::out);
    writeNRandomlyNumbersInFile(10000000, file);

    HeapSort obj;

    string ns;
    string hi;
    string hh;
    string h;

    for (int i = 10000; i < 1000000; i += 10000) {

        vld times;

        {
            string tmp;
            stringstream ss;
            ss << i;
            ss >> tmp;
            ns += tmp + ",";
        }

        {
            S_C_TP start = system_clock::now();
            obj.heapSort(getNIntFromFile(i, file));
            S_C_TP end = system_clock::now();

            DD elapsed_seconds = duration_cast<milliseconds>(end - start);
            times.push_back(elapsed_seconds.count());
        }
        {
            S_C_TP start = system_clock::now();
            obj._insert(getNIntFromFile(i, file));
            S_C_TP end = system_clock::now();

            DD elapsed_seconds = duration_cast<milliseconds>(end - start);
            times.push_back(elapsed_seconds.count());

        }
        {
            S_C_TP start = system_clock::now();
            obj.heapfiy(getNIntFromFile(i, file));
            S_C_TP end = system_clock::now();

            DD elapsed_seconds = duration_cast<milliseconds>(end - start);
            times.push_back(elapsed_seconds.count());

        }

        {
            string tmp;
            stringstream ss;
            ss << times[0];
            ss >> tmp;
            hi += tmp + ",";
        }
        {
            string tmp;
            stringstream ss;
            ss<<times[1];
            ss>>tmp;
            hh+= tmp + ",";
        }
        {
            string tmp;
            stringstream ss;
            ss<<times[2];
            ss>>tmp;
            h+= tmp + ",";
        }


    }



    string json="{\n"
                "\"n\": ["+ns.substr(0,ns.length()-1)+"],\n"
                "\"insert\": ["+hi.substr(0,ns.length()-1)+"],\n"
                "\"heapfiy\": ["+hh.substr(0,ns.length()-1)+"],\n"
                "\"heapsort\": ["+h.substr(0,ns.length()-1)+"]\n"
                "}";
    jsonfile<<json;



    file.close();
    jsonfile.close();
    return 0;
}
