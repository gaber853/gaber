Image Skewing(Image &work_on)
{
    int m = max(work_on.height, work_on.width);
    int W = work_on.width, H = work_on.height;
    Resize(work_on, m, m);

    Image blank(work_on.width * 2, work_on.height);
    int cnt = work_on.width;

    for (int j = 0; j < work_on.height; j++)
    {
        for (int i = 0; i < work_on.width; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                blank(i + cnt - j, j, k) = work_on(i, j, k);
            }
        }
    }
    Resize(blank, W, H);
    return blank;
}
