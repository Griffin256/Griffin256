const http = require('http');
const fs = require('fs');

const server = http.createServer((req, res) => {
    fs.readFile('payload.apk', (err, data) => {
        if (err) {
            res.writeHead(500, {'Content-Type': 'text/plain'});
            res.end('Server Error');
            return;
        }

        res.writeHead(200, {'Content-Type': 'application/vnd.android.package-archive'});
        res.end(data);
    });
});

server.listen(8080, () => {
    console.log('Server running on port 8080');
});
