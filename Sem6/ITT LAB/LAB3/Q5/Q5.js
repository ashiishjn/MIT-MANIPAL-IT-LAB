var sq;
var cu;
var cube = "cu-";
var square = "sq-";
var i;
function sqarecube(){
    for(i=0;i<=9;i++)
    {
        sq=i*i;
        cu=i*i*i;
        cube+=i.toString();
        square+=i.toString();
        document.getElementById(square).textContent = sq;
        document.getElementById(cube).textContent = cu;
        cube=cube.substring(0,3);
        square=square.substring(0,3);
    }
}
sqarecube();