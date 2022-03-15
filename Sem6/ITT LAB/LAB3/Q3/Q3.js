var phone = document.getElementById("Q3").value;
function get()
{
    var phoneno=document.getElementById("Q3").value;
    var a=phoneno.split(" ");
    var areacode = a[0].substring(1,a[0].length-1);
    var phon = a[1]+a[2];
    document.getElementById("area-code").value = areacode;
    document.getElementById("phone-no").value = phon;
}