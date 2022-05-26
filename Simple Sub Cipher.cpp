/*
Subject : Simple Substitution cipher " A2 for DR.ElRamly"
 Author : Mohamed Ahmed Abd Elquawy
 Date of last modification : 5/4/2022
*/
#include <iostream>
#include<string>
#include <string.h>
#include<algorithm>
#include<list>
#include <cctype>
using namespace std;
void simple_sub_encr(string key , string sent);
void simple_sub_decr(string key , string sent);
int main()
{
    int ans;
    char key[5];
    string sent="";
    while(ans!=3)
    {
    cout<<"Ahlan ya user ya habibi. \n";
    cout<<" What do you like to do today? \n ";
    cout<<"1- Cipher a message \n 2- Decipher a message \n 3- Exit \n";
    cin >> ans;
    if(ans ==1)
    {
        cout<<"Please, Enter a key contains only 5 characters: \n ";
        cin>>key;
        while(string(key).size()!=5)
        {
            cout<<"Please, Enter a valid key contains only 5 characters: \n ";
            cin>>key;
        }
        cout<<"Please enter the message : \n";
        cin.ignore();
        getline(cin,sent);
        simple_sub_encr(string (key) ,sent);
    }
    else if (ans==2)
    {
        cout<<"Please, Enter a key contains only 5 characters: \n ";
        cin>>key;
         while(string(key).size()!=5){
            cout<<"Please, Enter a valid key contains only 5 characters: \n ";
            cin>>key;
        }
        cout<<"Please enter the message : \n";
        cin.ignore();
        getline(cin,sent);
        simple_sub_decr(string (key) ,sent);
    }
    else if (ans=3)
    {
        cout<<"Thanks for using our program :) \n";
    }
    }
}

//______________________________________________

void simple_sub_encr(string key , string sent)
{
    string o_list=("abcdefghijklmnopqrstuvwxyz");
    string p_list=o_list;
    for(int n=0;n<=4;n++)
    {
        o_list.erase(remove(o_list.begin(), o_list.end(), key[n]));
    }
    for(int i=4;i>=0;i--)
    {
        o_list=key[i]+o_list;
    }
    string enc_sent=sent;
    for(int i=0;i<=sent.size();i++)
    {
        for(int x=0;x<=25;x++)
        {
            if(sent[i]==p_list[x]||sent[i]==toupper(p_list[x]))
            {
                enc_sent[i]=o_list[x];
            }
        }
    }
    cout<<"Your message after encryption is : \n"<<enc_sent<<endl;
}

//_________________________________________________

void simple_sub_decr(string key , string sent)
{
    string o_list="abcdefghijklmnopqrstuvwxyz";
    string p_list="abcdefghijklmnopqrstuvwxyz";
    for(int n=0;n<=4;n++)
    {
        o_list.erase(remove(o_list.begin(), o_list.end(), key[n]));
    }
    for(int i=4;i>=0;i--)
    {
        o_list=key[i]+o_list;
    }
    string dec_sent=sent;
    for(int i=0;i<sent.size();i++)
    {
        for(int j=0;j<26;j++)
        {
            if(sent[i]==o_list[j]||sent[i]==toupper(o_list[j]))
            {
                dec_sent[i]=p_list[j];
            }
        }
    }
    cout<<"Your message after decryption is : \n"<<dec_sent<<endl;
    }

