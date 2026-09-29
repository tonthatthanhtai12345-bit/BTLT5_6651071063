function Student(name, numberID, gender) {
  this.Name = name;
  this.NumberID = numberID;
  this.Gender = gender;
}
var sv = new Student("Nguyễn Văn A", "6651071063", "Nam");
document.getElementById("kq").innerHTML =
  "Name: " + sv.Name + "<br>NumberID: " + sv.NumberID + "<br>Gender: " + sv.Gender;
