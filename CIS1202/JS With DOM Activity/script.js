const btnShuffleImage = document.querySelector(".btn--shuffle-image");
const headerImage = document.querySelector('[alt="Banner Image"]');
const textArea = document.querySelector(".form-control");

imgNumber = 1 // number to determine which banner-x.jpg to use, where x is (imgNumber % 5 + 1)
btnShuffleImage.addEventListener("click", (e) => {
    imgNumber++; // increments to move to the next image
    headerImage.setAttribute('src', `./res/banner-${imgNumber % 5 + 1}.jpg`);
})

textArea.addEventListener('keydown', (e) => {
    if (textArea.value.length >= 10) {
        textArea.classList.add('is-invalid');
    }
})

textArea.addEventListener('keyup', (e) => {
    if (textArea.value.length < 10) {
        textArea.classList.remove('is-invalid');
    }
})