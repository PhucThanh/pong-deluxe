## class Console :

 Chú ý 
 - console_width, console_height : kích thương console thật.
 - game_width, game_height : số dòng và số cột trong game.
 - font_x,font_y : kích thước font.
 
**Note : hầu hết thao tác trong game sẽ sử dụng game_width và game_height**
Hàm console chỉ có một mục đích duy nhất đó chính là constructor của nó xây dựng console, set font, size, tránh thay đổi kích thước, bỏ thanh kéo,... Và console chỉ có 1 mục đích đó th. Cách hàm khác trong console sẽ bị xóa và thay thế bởi Graphic.
Chỉ cần tạo một object Console trong main để gọi constructor là xong, ko đụng gì đến nó nữa.
## class Graphic :
Đây là lớp static, nghĩa là không khai báo nó mà chỉ được gọi hàm trực tiếp. Tuy nhiên cần phải gọi hàm constructor của nó (memset) nên trong main tạo 1 đối tượng Graphic và để đó không đụng đến nó. Sẽ tìm cách fix điều này sau.
**Class Graphic** có nhiệm vụ quản lý đồ họa. Chỉ cần gọi Graphic::Draw(), truyền vào tọa độ, ký tự, màu sắc. Ngoài ra thiết kế thêm nhiều hàm vẽ phụ trợ như DrawString() : vẽ chữ, DrawRec() vẽ hình chữ nhật. Phát sinh những hàm vẽ khác nếu cần.
Lưu ý : Hàm Graphic::Update() sẽ update lên màn hình. Nếu gọi Draw không gọi update thì sẽ không có gì thay đổi. Hàm update là xài chung, nghĩa là mọi thứ draw xong mới update một lần, không phải draw là update liền.
Hàm goToXY gần như bị thay thế bởi Draw và ko cần sử dụng.
## Note
Trái banh không lag khi bắn góc xéo 45. Mọi góc khác sẽ bị cà giựt.
Biết Draw() thì phải biết xóa (Draw khoảng trống đè lên). 
Sửa lại tưng banh đổi hướng.
Trong hàm game sẽ thấy current_time, timeSinceBegin. 2 thứ này dùng để chỉnh tốc độ cho game. Giống như sleep mà cái này hay hơn. Tốc độ hiện tại là số 25, nghĩa là 25 tick mới update 1 lần