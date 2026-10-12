int main()
{
    string fname, newname, dec;
    bool flag = true, OnlyFirstTime = false, val = false;
    cout << "Enter the name of the image file & extention: \n";
    // cin >> fname;
    getline(cin, fname);

    while (!CheckExtension(fname))
    {
        cout << "Wrong image extension. Please enter a valid image file (.jpg, .jpeg, .png, .bmp): \n";
        // cin >> fname;
        getline(cin, fname);
    }

    Image backup(fname);
    Image work_on(fname);
    do
    {
        if (OnlyFirstTime && val)
        {
            string crt;
            while (true)
            {
                cout << "would you like to contenue on current image or back to old? \n";
                cout << "type(crt/old)\n";
                cin >> crt;
                if (crt == "crt" || crt == "old")
                    break;
                cout << "Invalid choice! Type 'crt' or 'old'.\n";
            }
            if (crt == "old")
            {
                work_on = backup;
            }
        }

        cout << "choose a Filter\n\n";
        cout << "0-info" << endl;
        cout << "1-Grayscale" << endl;
        cout << "2-Black and White" << endl;
        cout << "3-Invert " << endl;
        cout << "4-Adding a Frame " << endl;
        cout << "5-Flip " << endl;
        cout << "6-Rotate " << endl;
        cout << "7-Darken and Lighten " << endl;
        cout << "8-Resizing " << endl;
        cout << "9-Merge " << endl;
        cout << "10-Detect Image Edges " << endl;
        cout << "11-Crop Images " << endl;
        cout << "12-Blur Images " << endl;
        cout << "13-SunLight " << endl;
        cout << "14-TV Images " << endl;
        cout << "15-Purpling " << endl;
        cout << "16-Infrared " << endl;
        cout << "17-Skewing " << endl;
        cout << "18-Oil painting " << endl;

        int choice;
        cin >> choice;

        if (cin.fail() || choice < 0 || choice > 18)
        {
            cout << "invalid number ,try again\n\n";
            clearStream();
            val = false;
            continue;
        }

        if (choice == 0)
        {
            int scl = 0;
            for (int i = 0; i < work_on.width; i++)
            {
                for (int j = 0; j < work_on.height; j++)
                {
                    int mid = (work_on(i, j, 0) + work_on(i, j, 1) + work_on(i, j, 2)) / 3;
                    scl += mid;
                }
            }
            scl /= work_on.width * work_on.height;
            cout << "You have unlocked the SECRET treasure chest \nIt`s your image infos !!!\n";
            cout << "width : " << work_on.width << endl;
            cout << "hieght : " << work_on.height << endl;
            cout << "brightness : " << scl << endl;
            continue;
        }
        else if (choice == 1)
        {
            Grayscale(work_on);
        }
        else if (choice == 2)
        {
            BlackAndWhite(work_on);
        }
        else if (choice == 3)
        {
            work_on = Invert(work_on);
        }
        else if (choice == 4)
        {
            AddFrame(work_on);
        }
        else if (choice == 5)
        {
            Flip(work_on);
        }
        else if (choice == 6)
        {
            int num;
            while (true)
            {
                cout << "how many times to rotate? \n";
                if (cin >> num && num > 0)
                    break;
                cout << "Invalid number! Enter a positive number.\n";
                clearStream();
            }
            while (num--)
            {
                work_on = Rotate(work_on);
            }
        }
        else if (choice == 7)
        {
            int type = 0;
            while (true)
            {
                cout << "1. Darken\n";
                cout << "2. Lighten\n";
                if (cin >> type && (type == 1 || type == 2))
                    break;
                cout << "Invalid choice! Enter 1 or 2.\n";
                clearStream();
            }

            work_on = DarkenAndLighten(work_on, type - 1);
        }
        else if (choice == 8)
        {
            int W, H;
            cout << "current size " << work_on.width << " * " << work_on.height << endl;
            while (true)
            {
                cout << "enter new width and hight : \n ";
                if (cin >> W >> H && W > 0 && H > 0)
                    break;
                cout << "Invalid numbers! Enter positive integers.\n";
                clearStream();
            }
            Resize(work_on, W, H);
        }
        else if (choice == 9)
        {
            string num;
            do
            {
                cout << "enter name & ext for the image: \n";
                cin >> num;
                // getline(cin, num);
            } while (!CheckExtension(num));
            Image img(num);
            work_on = Merge(work_on, img);
        }
        else if (choice == 10)
        {
            DetectEdges(work_on);
        }
        else if (choice == 11)
        {
            Crop(work_on);
        }
        else if (choice == 12)
        {
            int l = 1;
            while (true)
            {
                cout << "enter bluring level 1 : 5 \n";
                if (cin >> l && l > 0)
                    break;
                cout << "Invalid number! Enter positive integer. \n";
                clearStream();
            }
            Blur(work_on, l);
        }
        else if (choice == 13)
        {
            SunLight(work_on);
        }
        else if (choice == 14)
        {
            TV(work_on);
        }
        else if (choice == 15)
        {
            Purple(work_on);
        }
        else if (choice == 16)
        {
            Infrared(work_on);
        }
        else if (choice == 17)
        {
            work_on = Skewing(work_on);
        }
        else if (choice == 18)
        {
            Oil(work_on);
        }

        val = true;
        cout << "DONE\n";
        cout << "want to save image?   type(y/n)\n";
        cin >> dec;
        if (dec[0] == 'y' || dec[0] == 'Y')
        {
            cout << "enter the file name & type which you want to save the new image in:  default(.jpg)\n";
            cout << "do not use spaces ' ' & same name will cause an overload\n";
            cin >> newname;
            // getline(cin, newname);

            if (!CheckExtension(newname))
                newname += ".jpg";

            work_on.saveImage(newname);
        }
        flag = false;

        cout << "contenue ?   type(Y/N)\n";
        cin >> dec;
        if (dec[0] == 'y' || dec[0] == 'Y')
            flag = true;

        OnlyFirstTime = true;

    } while (flag);

    cout << "Thanks for using our photoshop app";
    return 0;
}
