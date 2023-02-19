const btnShuffleImage = document.querySelector('.btn--shuffle-image');
const headerImage = document.querySelector("[alt='Banner Image']");

const btnTextAppend = document.querySelector('.btn--text-append');
const textArea = document.querySelector('.form-control');
const appendArea = document.querySelector('.append-area');

const btnFindReplace = document.querySelector('.btn--find-replace');

// shuffles the banner image forward by 1 image, max is until banner-5.jpg
imgNumber = 1 // number to determine which banner-x.jpg to use, where x is (imgNumber % 5 + 1)
btnShuffleImage.addEventListener('click', (e) => {
    imgNumber++; // increments to move to the next image
    headerImage.setAttribute('src', `./res/banner-${imgNumber % 5 + 1}.jpg`);
})

// textarea validation logic for handling the max of 1000 characters
textArea.addEventListener('keyup', (e) => {
    if (textArea.value.length > 1000) {
        textArea.classList.add('is-invalid');
    }
    else if (textArea.value.length < 1001) {
        textArea.classList.remove('is-invalid');
    }
})

// when you click the append button, set the appendArea's text to its current + whatever is in textArea
btnTextAppend.addEventListener('click', (e) => {
    if (textArea.value.length < 1001) {
        appendArea.textContent = appendArea.textContent + ` ${textArea.value}`;
    }
})

// replaces all the occurences of textToFind with textToReplace using the replaceAll method which returns a string to be assigned to the node's textContent property
btnFindReplace.addEventListener('click', (e) => {
    textToFind = prompt("What term would you like to replace?");
    textToReplace = prompt("What will you replace it with?");

    // selects all the tags
    headerOne = document.querySelector('h1');
    headerList = document.querySelectorAll('h2');
    paragraphList = document.querySelectorAll('p');

    headerOne.textContent = headerOne.textContent.replaceAll(textToFind, textToReplace)

    headerList.forEach((e) => {
        e.textContent = e.textContent.replaceAll(textToFind, textToReplace)
    });

    paragraphList.forEach((e) => {
        e.textContent = e.textContent.replaceAll(textToFind, textToReplace)
    });
})