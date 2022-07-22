void help(vector<vector<int>> &image, int x, int y, int Color ,int curr,int M,int N){
    if(x>=M||x<0||y>=N||y<0)
        return ;
    
    if(image[x][y]==curr){
        image[x][y]=Color;
        help(image,x-1,y,Color,curr,M,N);
        help(image,x,y-1,Color,curr,M,N);
        help(image,x+1,y,Color,curr,M,N);
        help(image,x,y+1,Color,curr,M,N);
        //cout<<x<<y<<endl;
    }
    else
        return ;
    
}


vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    if(image[x][y] == newColor) return image;
    int curr=image[x][y];
    int M=image.size();
    int N=image[0].size();
    help(image,x,y,newColor,curr,M,N);
    return image;
}
