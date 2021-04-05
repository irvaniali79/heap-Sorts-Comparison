#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>

namespace HeapSort_
{
    using namespace std;

    typedef vector<int> vi;
    class HeapSort
    {
    public:
        void sort(vi &arr)
        {
            heapSort(arr);
        };

    protected:
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

    private:
        virtual void heapSort(vi &arr) = 0;
    };

    class HeapSortWithInserion : public HeapSort
    {

    private:
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

        void heapSort(vi &arr)
        {

            for (int i = arr.size() - 1; i >= 1; --i)
            {
                insert(arr, 1);
            }

            for (int i = arr.size() - 1; i > 0; i--)
            {
                swap(arr[0], arr[i]);
                adjust(arr, 0);
            }
        }
    };

    class HeapSortWithHeapfiy : public HeapSort
    {

    private:
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
    };
}

using namespace HeapSort_;
using namespace chrono;

typedef vector<long double> vld;
typedef duration<double> DD;
typedef system_clock::time_point S_C_TP;

void writeNRandomlyNumbersInFile(int n, fstream &file)
{
    srand(time(nullptr));
    for (int i = 0; i < n; ++i)
    {
        file << rand() << " ";
    }
    file.seekp(ios::beg); //change curser pointer to first
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
vld measureTimeComplexity(vi &input, vector<HeapSort *> &algos)
{
    vld times;
    for (HeapSort *algo : algos)
    {
        S_C_TP start = system_clock::now();
        algo->sort(input);
        S_C_TP end = system_clock::now();
        DD elapsed_seconds = duration_cast<milliseconds>(end - start);
        times.push_back(elapsed_seconds.count());
    }
    return times;
}

int main()
{
    fstream file("generatednumbers.txt", ios::out);
    fstream docpage("table.xls", ios::out | ios::app);
    writeNRandomlyNumbersInFile(10000000, file);
    vector<HeapSort *> x;
    HeapSortWithHeapfiy A;
    HeapSortWithInserion B;
    x.push_back(&A);
    x.push_back(&B);

    docpage<<"n\tH_heapfiy\tH_insert"<<endl;
//    string lables="[";
    for (int i = 10000; i < 1000000; i += 10000)
    {

        vld times;
        docpage << i << '\t';
        times = measureTimeComplexity(getNIntFromFile(i, file), x);
        for (int j = 0; j < 2; ++j)
        {
            docpage << times[j] << '\t';
        }
        docpage << endl;
//        stringstream ss;
//        ss << i;
//        string str;
//        ss >> str;

//        lables+="\""+str+"\",";


    }
//    lables="]";
    /*string page="<html land>"
                "<head>"
                "<meta charset=\"UTF-8\">"
                "<meta content=\"text/html; charset=utf-8\" http-equiv=\"Content-Type\">"
                "<title>Line · Chart.js documentation</title>"
                "<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">"
                "<meta name=\"description\" content=\"\">"
                "<meta name=\"generator\" content=\"GitBook 3.2.2\">"
                "<meta name=\"author\" content=\"chartjs\">"
                "<style class=\"anchorjs\"></style><link rel=\"stylesheet\" href=\"../gitbook/style.css\">     "
                "<link rel=\"stylesheet\" href=\"../gitbook/gitbook-plugin-search-plus/search.css\">"
                "<link rel=\"stylesheet\" href=\"../gitbook/gitbook-plugin-highlight/website.css\">"
                           "<link rel=\"stylesheet\" href=\"../gitbook/gitbook-plugin-fontsettings/website.css\">"
                           "<link rel=\"stylesheet\" href=\"../style.css\">"
                   "<meta name=\"HandheldFriendly\" content=\"true\"><meta name=\"viewport\" content=\"width=device-width, initial-scale=1, user-scalable=no\">"
                "<meta name=\"apple-mobile-web-app-capable\" content=\"yes\"> <meta name=\"apple-mobile-web-app-status-bar-style\" content=\"black\">"
                "<link rel=\"apple-touch-icon-precomposed\" sizes=\"152x152\" href=\"../gitbook/images/apple-touch-icon-precomposed-152.png\">"
               "<link rel=\"shortcut icon\" href=\"../gitbook/images/favicon.ico\" type=\"image/x-icon\"><link rel=\"stylesheet\" href=\"../gitbook/gitbook-plugin-chartjs/style.css\">"
               "<script async=\"\" src=\"//www.google-analytics.com/analytics.js\"></script><script src=\"../gitbook/gitbook-plugin-chartjs/Chart.bundle.js\"></script>"
                   "<script src=\"../gitbook/gitbook-plugin-chartjs/chartjs-plugin-deferred.js\"></script><link rel=\"prev\" href=\"./\"><link rel=\"next\" href=\"bar.html\">"
                 "</head><body><div class= \"chartjs-wrapper\"><iframe class = \"chartjs-hidden-iframe\" tabindex = \"-1\" style = \"display: block; overflow: hidden; border: 0px; margin: 0px; inset: 0px; height: 100%; width: 100%; position: absolute; pointer-events: none; z-index: -1;\" __idm_frm__ = \"57\"></ iframe><canvas id = \"chartjs-0\" class = \"chartjs\" width = \"810\" height = \"405\" style = \"display: block; height: 324px; width: 648px;\"></ canvas><script> new Chart(document.getElementById(\"chartjs-0\"), {\"type\" : \"line\", \"data\" : {\"labels\" : "+lables+", \"datasets\" : [ {\"label\" : \"My First Dataset\", \"data\" : [ 1, 0.90, 0.80, 0.75, 0.50, 0.25, 0 ], \"fill\" : false, \"borderColor\" : \"rgb(75, 192, 192)\", \"lineTension\" : 0.1} ]}, \"options\" : {}});"
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        "</ script></ div> </body></html>"
    ;*/
//    docpage<<page;
    file.close();
    docpage.close();

    return 0;
}
