var i,j,k;
var str;
var out="";
function fun()
{
    var text = document.getElementById("input").value;
    for(i=0;i<3;i++)
    {
        str=text.charAt(i);
        for(j=i+1;j<4;j++)
        {
            str+=text.charAt(j);
            for(k=j+1;k<5;k++)
            {
                str+=text.charAt(k);
                out+=str+",";
                str=str.substring(0,2);
            }
            str=str.substring(0,1);
        }
    }
    document.getElementById("output").textContent = out;
}