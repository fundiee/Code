const form = document.querySelector('#loginForm');

form.addEventListener('submit', async function(event) {
    event.preventDefault();

    let data = {
        username: form.username.value,
        password: form.password.value
    };

    const response = await fetch('/login', {
        method: 'POST',
        headers: {'Content-Type': 'application/json'},
        body: JSON.stringify(data)
    });

    form.username.value = "";
    form.password.value = "";

    let result = await response.json();
    // shows in browser console
    console.log(result.message);
});