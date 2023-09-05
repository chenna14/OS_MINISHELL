#include<bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


using namespace std;


// take string and return words

vector<string> split(string s)
{
    vector<string> words;
    string word;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            words.push_back(word);
            word="";
        }
        else
        {
            word+=s[i];
        }
    }
    words.push_back(word);
    return words;
}


int main(int argc,char *arg[])
{
    
    while(1)
    {
        string s;

        string curr;

        char cwd[1024];

        getcwd(cwd, sizeof(cwd));

        curr = cwd;

        cout<<curr<<" $ ";

        getline(cin,s);

        vector<string> words = split(s);

        int n = words.size();

        if(words[0] == "ls")
        {
            execvp("ls",arg);
        }
        else if(words[0] == "cd" && n==1)
        {
            // chdir(words[1].c_str());
            chdir(getenv("HOME"));
        }
        else if(words[0] == "cd" && n==2)
        {
            chdir(words[1].c_str());
        }

        else if(words[1][0] == '<')
        {

            // write to file

            string file = words[2];


            int fd = open(file.c_str(),O_WRONLY | O_CREAT | O_TRUNC, 0644);

            dup2(fd,1);


            // execute

            char *args[n+1];

            for(int i=0;i<n;i++)
            {
                args[i] = (char *)words[i].c_str();

            }

            args[n] = NULL;

            execvp(args[0],args);

            ofstream fout;

            fout.open(file);

            fout.close();

            





          




        } 


    }

}