#include <iostream>
#include <string>
#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <array>
#include <unistd.h>
using namespace std;

string exec(const char* cmd);

int main(){


     string apps[100];
     //string dockapps =
     //dockapps.find("file-label");
     //string dockapps = "needle in needle in needle";
     int occurrences = 0;
     string::size_type pos = 0;
     string s = exec("defaults read com.apple.dock persistent-apps");
     string target = "file-label";
     while ((pos = s.find(target, pos )) != std::string::npos) {
         ++ occurrences;
         apps[occurrences] = s.substr(pos+14, s.substr(pos,pos+60).find(';')-12);
         //pos += target.length();
         pos += 900;
    }

    for(int i = 0; i < occurrences+1; i++){

        apps[i].erase(std::remove(apps[i].begin(), apps[i].end(), '\"'), apps[i].end());
        apps[i].erase(std::remove(apps[i].begin(), apps[i].end(), ';'), apps[i].end());
        apps[i].erase(std::remove(apps[i].begin(), apps[i].end(), '\n'), apps[i].end());

    }


     string func = "osascript -e 'tell application \"" + apps[3] +"\" to open'";

     string functwo = "osascript -e 'tell application \"" + apps[3] +"\" to close'";

     string osa = "osascript -e 'display dialog \"calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com calhat.com \" buttons {\"Cancel\", \"Start\"}default button 2'";

     string ans = exec(osa.c_str());

     if (ans.find("Start") < 40){
          cout<<"hi";
     }

     else if(ans.find("Cancel") == string::npos){
          cout<<"peace!";
          exit(EXIT_FAILURE);
     }


     for(int i = 1; i< occurrences+1 ;i++){

     if (apps[i] != "dockfun" && apps[i] != "Launchpad" && apps[i] != "QuickTime Player"){

     //if (apps[i] != "Launchpad" &&  apps[i] != "Siri" && apps[i] != "SPORE" && apps[i] != "FL Studio" && apps[i] != "iHaxGamez"){
          if (apps[i].find(' ')!=string::npos){
               int blah = apps[i].find(' ');
               apps[i] = apps[i].substr(0,blah) + "\\"+ apps[i].substr(blah);
               }
     func = "open -a" + apps[i];

     functwo = "killall " + apps[i];

     cout<<apps[i]<< " opening..."<<endl;

     system(func.c_str());
     //usleep(20000);
     system(functwo.c_str());
     system(functwo.c_str());
     }
//}

     }

     for(int i = occurrences; i > 0 ;i--){
     if (apps[i] != "dockfun" && apps[i] != "Launchpad" && apps[i] != "QuickTime Player"){

     //if (apps[i] != "Launchpad" &&  apps[i] != "Siri" && apps[i] != "SPORE" && apps[i] != "FL Studio" && apps[i] != "iHaxGamez"){

     func = "open -a" + apps[i];

     functwo = "killall " + apps[i];

     cout<<apps[i]<< " opening..."<<endl;

     system(func.c_str());
     //usleep(20000);
     system(functwo.c_str());
     system(functwo.c_str());
}
//}

     }


}

string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != NULL)
            result += buffer.data();
    }
    return result;
}
