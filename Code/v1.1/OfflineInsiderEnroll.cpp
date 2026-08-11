#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void reset( )
{
    system("reg delete HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost /f");
}

void clean_up( )
{
    string input;
    cout << "需要重新启动以完成更改，要现在重启吗? (Y/N) ";
    cin >> input;
    while(1)
    {
        if(input == "Y")
        {
            system("shutdown -r -t 0");
         }
             else if(input == "N")
         {
             break;
         }
        else
         {
             cout << "输入错误！请重新输入。";
             cin >> input;
             continue;
         }
    }
}

void ready( )
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v ContentType /t REG_SZ /d Mainline /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v Ring /t REG_SZ /d External /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v RingId /t REG_DWORD /d 11 /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIRing /t REG_SZ /d External /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIContentType /t REG_SZ /d Mainline /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v EulaAccepted /t REG_DWORD /d 1 /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\OneSettings /f /t REG_DWORD /v FlightSettingsVersion /d 2");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\OneSettings /f /t REG_DWORD /v IsBuildUnsupported /d 0");
}

void Experimental_FP( )
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d CanaryChannel /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UITargetVersion /t REG_DWORD /d 0 /f");
}

void Experimental_26H1( )
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UITargetVersion /t REG_DWORD /d 28000 /f");
}

void Experimental( )
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d Dev /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UITargetVersion /t REG_DWORD /d 26200 /f");
}

void Beta( )
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d Beta /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d Beta /f");
}

void ReleasePreview( )
{
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\Applicability /v BranchName /t REG_SZ /d ReleasePreview /f");
    system("reg add HKLM\\SOFTWARE\\Microsoft\\WindowsSelfHost\\UI\\Selection /v UIBranch /t REG_SZ /d ReleasePreview /f");
}

int main( )
{
    system("chcp 65001"); 
    int notAdmin = system("reg query HKU\\S-1-5-19 1>nul 2>nul");
    if(notAdmin == 0)
    {
        cout << "欢迎使用本程序！" << endl;
     }
     else
     {
        cout << "请以管理员身份运行本程序！" << endl;
        system("pause");
        return 0;
    }
    cout << "请选择要执行的操作" << endl;
    cout << "操作列表" << endl << endl;
    cout << "代号    | 操作                    | 目标版本               | 目标版本号   | 旧频道名称" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "1       | 加入 实验性 频道        | 未来平台               | 29639.1000   | Canary" << endl;
    cout << "2       | 加入 实验性 频道        | 26H1                   | 28120.2630   | Dev" << endl;
    cout << "3       | 加入 实验性 频道        | 26H2                   | 26300.9032   | Dev" << endl;
    cout << "4       | 加入 Beta 频道          | 25H2                   | 26220.9022   | Beta" << endl;
    cout << "5       | 加入 发行预览 频道      | 25H2                   | 26100+       | RP" << endl << endl;
    cout << "6       | 重设预览版设置，使其恢复到运行本程序前的设置" << endl;
    cout << "7       | 离开本程序而不作任何修改" << endl << endl;
    int input = 0;
    while(input == 0)
    {
        cout << "请输入代表操作的代号：";
        cin >> input;
        if(input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input == 6 || input == 7)
        {
            break;
         }
         else
         {
            cout << "请输入正确的代号！";
            input = 0;
            continue;
        }
    }
    if(input == 1)
    {
        ready();
        Experimental_FP();
        clean_up();
        return 0;
    }
    if(input == 2)
    {
        ready();
        Experimental_26H1();
        clean_up();
        return 0;
    }
    if(input == 3)
    {
        ready();
        Experimental();
        clean_up();
        return 0;
    }
    if(input == 4)
    {
        ready();
        Beta();
        clean_up();
        return 0;
    }
    if(input == 5)
    {
        ready();
        ReleasePreview();
        clean_up();
        return 0;
    }
    if(input == 6)
    {
        reset();
        clean_up();
        return 0;
    }
    if(input == 7)
    {
        return 0;
    }
    
    return 0;
}
