
int main(int argc, char const *argv[])
{
    short int  a = 0x1234;
    char *p = &a;
    printf("低字节 : %0x\n",*p);
    printf("低字节 : %0x\n",*(p+1));
    return 0;
}
