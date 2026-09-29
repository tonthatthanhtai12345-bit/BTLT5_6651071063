var u = { Name: "Max", Age: 20 };
var out = "a) Thông tin u: " + JSON.stringify(u);
u.Surname = "Lee";
out += "\nb) Sau khi thêm Surname: " + JSON.stringify(u);
u.Age = 30;
out += "\nc) Sau khi đổi Age = 30: " + JSON.stringify(u);
document.getElementById("kq").innerText = out;
