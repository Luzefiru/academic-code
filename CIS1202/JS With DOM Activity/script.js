btnShuffleImage = document.querySelector(".btn--shuffle-image")
headerImage = document.querySelector('[alt="Banner Image"]')

imgNumber = 1 // number to determine which banner-x.jpg to use, where x is (imgNumber % 5 + 1)
btnShuffleImage.addEventListener("click", (e) => {
    imgNumber++; // increments to move to the next image
    headerImage.setAttribute('src', `./res/banner-${imgNumber % 5 + 1}.jpg`);
})