#include <bits/stdc++.h>

#include "tovar.cpp"

using namespace std;

int main()
{
    tovar *moi_fail = NULL;
    int b = 0;
    string c;
    while (1)
    {
        cout << "--------------------------" << endl;
        cout << "tap [1] for din videlenie pamiati" << endl;
        cout << "tap [2] for vvod_massiva_s_klav_" << endl;
        cout << "tap [3] for poisk_elementa_massiva" << endl;
        cout << "tap [4] for sort" << endl;
        cout << "tap [5] for redaktirovanie_elementov" << endl;
        cout << "tap [6] for push_back" << endl;
        cout << "tap [7] for delete_element" << endl;
        cout << "tap [8] for vstavka_novogo_elementa" << endl;
        cout << "tap [9] for zapiss_elementov_v_fail" << endl;
        cout << "tap [10] for scitivanie_elementov_iz_faila" << endl;
        cout << "tap [11] for vivod_massiva_na_ekran" << endl;
        cout << "tap [12] for osvobojdenie_pamiati" << endl;
        cout << "tap [13] for konets_raboti" << endl;
        cout << "-------------------------------------" << endl;
        cin >> c;
        cout << endl;
        if (c[0] == '1' && c[1] == '\0')
        {
            dinamiceskoe_videlenie_pamiati(moi_fail, b);
        }
        else if (c[0] == '2' && c[1] == '\0')
        {
            vvod_massiva_s_klav_(moi_fail, b);
        }
        else if (c[0] == '3' && c[1] == '\0')
        {
            poisk_elementa_massiva(moi_fail, b);
        }
        else if (c[0] == '4' && c[1] == '\0')
        {
            sortirovka(moi_fail, b);
        }
        else if (c[0] == '5' && c[1] == '\0')
        {
            redaktirovanie_elementov(moi_fail, b);
        }
        else if (c[0] == '6' && c[1] == '\0')
        {
            push_back(moi_fail, b);
        }
        else if (c[0] == '7' && c[1] == '\0')
        {
            delete_element(moi_fail, b);
        }
        else if (c[0] == '8' && c[1] == '\0')
        {
            vstavka_novogo_elementa(moi_fail, b);
        }
        else if (c[0] == '9' && c[1] == '\0')
        {
            zapiss_elementov_v_fail(moi_fail, b, "lab6_7_zapis.txt");
        }
        else if ((c[0] == '1' && c[1] == '0') && c[2] == '\0')
        {
            scitivanie_elementov_iz_faila(moi_fail, "lab6_7_txt_.txt", b);
        }
        else if ((c[0] == '1' && c[1] == '1') && c[2] == '\0')
        {
            vivod_massiva_na_ekran(moi_fail, b);
        }
        else if ((c[0] == '1' && c[1] == '2') && c[2] == '\0')
        {
            osvobojdenie_pamiati(moi_fail, b);
        }
        else if ((c[0] == '1' && c[1] == '3') && c[2] == '\0')
        {
            break;
        }
        else
        {
            c = "";
        }
    }
    return 0;
}
