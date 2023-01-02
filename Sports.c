#include<stdio.h>
#include<string.h>
void deleteProduct();
void buyProduct();
struct Sports{
    char name[200];
    int a,b,qty;
};

void main(){
    int n;
    char ch;
    FILE *fptr;

    printf("\n\t<<<<<<<<<< Welcome to Sports Store Management System >>>>>>>>>>\n\n");
    printf("\t\t1. Display the Products\n");
    printf("\t\t2. Add a product\n");
    printf("\t\t3. Delete a product\n");
    printf("\t\t4. Buy products\n");
    printf("\t\t0. Exit\n");
    printf("\t\tEnter your choice: ");
    scanf("%d", &n);
    printf("\n\n");

    switch(n) {
    exit:   case 0: printf("\n\t\t---------<><><><> Thanks Visit Again...! <><><><>---------\n\n");
                    break;
            case 1: fptr = fopen("product.txt", "r");
                    ch = fgetc(fptr);
                    int d;
                    while(ch!= EOF) {
                        printf("%c", ch);
                        ch = fgetc(fptr);
                    }
                    printf("\n");
                    fclose(fptr);

                    printf("\n\tEnter (2-4) to Add, Delete or Buy another products: ");
                    scanf("%d", &d);
                    if(d == 2){
                        goto add;
                    } else if(d == 3) {
                        goto del;
                    } else if(d == 4) {
                        goto buy;
                    } else {
                        goto exit;
                    }
                    break;
    add:    case 2: fptr = fopen("product.txt", "a");
                    //int a, b, c;
                    //char name[200];
                    int c;
                    struct Sports s1[100];
                    printf("\n\t-----<><><> Add Products <><><>-----");
                    printf("\n\tEnter the Sr. No. of product: ");
                    scanf("%d%*c", &s1[0].a); //or use getchar() after scanf("%d",&a);

                    printf("\n\tEnter the name of product: ");
                    gets(s1[0].name); // or use scanf("%[^\n]%*c", name);

                    printf("\n\tEnter the price of product: ");
                    scanf("%d", &s1[0].b);

                    fprintf(fptr,"\n\t%d.\t%s\t-------------- Rs.%d",s1[0].a,s1[0].name,s1[0].b);
                    //fprintf(fptr,"\t%s\t--------------",name);
                    //fprintf(fptr," Rs.%d",a);

                    fclose(fptr);
                    printf("\tProduct added sucessfully..");
                    printf("\n\tNow the List of products is:\n\n");
                    fptr = fopen("product.txt", "r");
                    ch = fgetc(fptr);
                    while(ch != EOF) {
                        printf("%c", ch);
                        ch = fgetc(fptr);
                    }
                    printf("\n");
                    fclose(fptr);

                    printf("\n\tEnter (2-4) to Add, Delete or Buy another product: ");
                    scanf("%d", &c);
                    if(c == 2) {
                        goto add;
                    } else if(c == 3) {
                        goto del;
                    } else if(c == 4) {
                        goto buy;
                    } else {
                        goto exit;
                    }
                    break;
    del:    case 3: deleteProduct();
                    printf("\n\tEnter (2-4) to Add, Delete or Buy another product: ");
                    scanf("%d", &c);
                    if(c == 2) {
                        goto add;
                    } else if(c == 3) {
                        goto del;
                    } else if(c == 4) {
                        goto buy;
                    } else {
                        goto exit;
                    }
                    break;
    buy:    case 4: buyProduct();
                    printf("\n\t Enter 0 to exit the system: ");
                    scanf("%d", &c);
                    if(c == 0) {
                        goto exit;
                    }
                    break;
            default: printf("\tInvalid input");

    }
  
}
void deleteProduct() {
    int lno, ctr = 0;
    char ch;
    FILE *fptr1, *fptr2;
    char fname[200];
        char str[200], temp[] = "temp.txt";
		printf("\n\n\t Delete a product from a file :\n");
		printf("\t-----------------------------------------\n"); 
		printf("\t Input the file name to be opened : ");
		scanf("%s",fname);		
        fptr1 = fopen(fname, "r");
        if (!fptr1) 
		{
                printf(" File not found or unable to open the input file!!\n");
                return;
        }
        fptr2 = fopen(temp, "w"); // open the temporary file in write mode 
        if (!fptr2) 
		{
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return;
        }
        printf("\n\t Input the line of product you want to remove : ");
        scanf("%d", &lno);
		lno++;
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1)) 
        {
            strcpy(str, "\0");
            fgets(str, 200, fptr1);
            if (!feof(fptr1)) 
            {
                ctr++;
                /* skip the line at given line number */
                if (ctr != lno) 
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }
        fclose(fptr1);
        fclose(fptr2);
        remove(fname);  		// remove the original file 
        rename(temp, fname); 	// rename the temporary file to original name
/*------ Read the file ----------------*/
        fptr1=fopen(fname,"r"); 
        ch=fgetc(fptr1); 
        printf("\n\n\tNow the list of products of file %s is : \n",fname); 
        while(ch!=EOF) 
        { 
            printf("%c",ch); 
            ch=fgetc(fptr1); 
        }
        fclose(fptr1);
}

void buyProduct() {
    struct Sports s[100];
    int i = 0, c = 1, x, amt;
    int y;
    float total = 0, sgst, cgst, igst, tgst;
    printf("\nEnter 1 if buying is done from GUJARAT or 2 from outside of GUJARAT: ");
    scanf("%d", &y);
    if(y == 1) {
        printf("Enter the current SGST: ");
        scanf("%f",&sgst);
        printf("Enter the current CGST: ");
        scanf("%f",&cgst);
        printf("Total GST: %f",tgst = sgst + cgst);
    } else {
        igst = 18;
    }
    
    printf("\n\n\t-----<><><> Buy Products <><><>-----");
    do {
        printf("\n\t Enter the item no.: ");
        scanf("%d%*c", &s[i].a);
        printf("\n\t Enter the product name: ");
        gets(s[i].name);
        printf("\n\t Enter quantity & price of product: ");
        scanf("%d %d", &s[i].qty, &s[i].b);
        //printf("\n\t Enter price of product: ");
        //scanf("%d", s[i].b);
        printf("\n\t Press 1 to more items: ");
        scanf("%d", &x);

        if(x == 1) {
            i++;
            c++;
        }
    } while(x == 1);
    printf("\n\t================================================================================");
    printf("\n\n\t\t\t\t\tB I L L I N G");
    printf("\n\n\t================================================================================");
    printf("\n\t%-20s%-20s%-10s%-21s%s"," Item No.","Items","Qty","Price","Amount");
    printf("\n\t--------------------------------------------------------------------------------\n");

    for(i=0;i<c;i++) {
        amt = s[i].qty * s[i].b;
        total = total + amt;
        printf("\t %-19d%-21s%-10d%-21d%d\n", s[i].a, s[i].name, s[i].qty, s[i].b, amt);
    }
    printf("\n\t--------------------------------------------------------------------------------\n");
    if(y == 1){
        printf("\t SGST:(@%f Perct.)%55f", sgst, amt * (sgst/100));
        printf("\n\t CGST:(@%f Perct.)%55f", cgst, amt * (cgst/100));
        printf("\n\t TOTAL PAYBLE AMOUNT:%59f", total = total + (total * (tgst/100)));
    } else {
        printf("\n\t IGST:(@%f Perct.)%55f", igst, amt * (igst/100));
        printf("\n\t TOTAL PAYBLE AMOUNT:%59f", total = total + (total * (igst/100)));
    }
}
