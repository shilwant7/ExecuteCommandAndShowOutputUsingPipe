#include<iostream>
#include <string.h>
using namespace std;

bool executeSystemCmd(string cmd)
{
    string data;
    FILE * stream;
    const int max_buffer = 256;
    char buffer[max_buffer];
    //cmd.append(" 2>&1");
    uint64_t loop_brake = 0;

    stream = popen(cmd.c_str(), "r");
    if (stream)
    {
        while (!feof(stream))
        {
            if (fgets(buffer, max_buffer, stream) != NULL)
                data.append(buffer);
                loop_brake++;
            if(loop_brake == 256)
                break;
        }
        pclose(stream);
    }
    else
    {
        return false;
    }
    cout<<"Given command: "<< cmd << endl;
    cout<<"Command output: \n"<<data<<endl;
    return true;
}

int main()
{
    string command{};
    #ifdef _WIN32
        command = "dir";
    #else
        command = "ls";
    #endif

    executeSystemCmd(command);

    return 0;
}
