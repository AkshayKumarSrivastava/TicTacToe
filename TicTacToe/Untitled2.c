                #include<windows.h>
                int main()
                {
                    int i;
                MessageBeep(1);
                i=MessageBoxA(NULL,"the given position is already occupied","ERROR!!!",MB_ICONERROR);
                printf("%d",i);
                return 0;
                }
