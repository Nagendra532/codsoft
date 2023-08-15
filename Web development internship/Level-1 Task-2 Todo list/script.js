const taskInput = document.getElementById('taskInput');
const addTaskButton = document.getElementById('addTask');
const taskList = document.getElementById('taskList');

addTaskButton.addEventListener('click', () => {
    const taskText = taskInput.value.trim();
    if (taskText !== '') {
        addTask(taskText);
        taskInput.value = '';
    }
});

function addTask(text) {
    const li = document.createElement('li');
    li.innerHTML = `
        <span>${text}</span>
        <button class="delete">Delete</button>
    `;
    taskList.appendChild(li);
    saveTasksToLocalStorage();
    addDeleteListener(li);
}

function addDeleteListener(li) {
    const deleteButton = li.querySelector('.delete');
    deleteButton.addEventListener('click', () => {
        li.remove();
        saveTasksToLocalStorage();
    });
}

function saveTasksToLocalStorage() {
    const tasks = Array.from(taskList.children).map(li => li.querySelector('span').innerText);
    localStorage.setItem('tasks', JSON.stringify(tasks));
}

function loadTasksFromLocalStorage() {
    const tasks = JSON.parse(localStorage.getItem('tasks')) || [];
    tasks.forEach(task => addTask(task));
}

loadTasksFromLocalStorage();
