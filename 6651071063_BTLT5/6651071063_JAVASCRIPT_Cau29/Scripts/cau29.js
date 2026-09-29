function getFormvalue() {
  var f = document.getElementById("form1");
  alert("Họ và tên: " + f.elements["fname"].value + " " + f.elements["lname"].value);
  return false; // không reload trang
}
